#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

typedef struct node
{
    int data;
    node *next;
} Node;

Node *createNode(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void printList(Node *head)
{
    Node *temp = head;
    if (temp == NULL)
        return;

    cout << "List: \n";
    while (temp)
    {
        cout << temp->data << "\t";
        temp = temp->next;
    }
    cout << endl;
}

Node *appendNewNode(Node *head, int data)
{
    if (head == NULL)
    {
        head = createNode(data);
        return head;
    }
    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = createNode(data);
    return head;
}

Node *insertNodeAtFront(Node *head, int data)
{
    Node *newNode = createNode(data);
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
    return head;
}

Node *insertAfter(int pos, int data, Node *head)
{
    if (head == NULL)
    {
        head = createNode(data);
        return head;
    }

    Node *newNode = createNode(data);
    Node *list_iter = head;
    for (int i = 1; i < pos; i++)
    {
        list_iter = list_iter->next;
    }
    newNode->next = list_iter->next;
    list_iter->next = newNode;
    return head;
}

string readData()
{
    string line;
    fstream file;
    file.open("input.txt", ios::in);
    if (file.is_open())
    {
        getline(file, line);
        cout << "Data: " << line << endl;
    }
    file.close();
    return line;
}

int main()
{
    Node *head = NULL;
    string data = readData();
    int num;
    stringstream ss(data);

    while (ss >> num)
    {
        if (num % 2 == 0)
        {
            head = appendNewNode(head, num);
        }
        else
        {
            head = insertNodeAtFront(head, num);
        }
    }
    printList(head);
    int loc, randomData;
    cout << "Enter position: " << endl;
    cin >> loc;
    cout << "Enter number: ";
    cin >> randomData;
    insertAfter(loc, randomData, head);
    printList(head);
    return 0;
}