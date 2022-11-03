#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

typedef struct node
{
    int data;
    node *next;
} Node;
Node *head = NULL;

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
}

void appendNewNode(int data)
{
    if (head == NULL)
    {
        head = createNode(data);
        return;
    }
    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    Node *newNode = createNode(data);
    temp->next = newNode;
}

void insertNodeAtFront(int data)
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
    string data = readData();
    int num;
    stringstream ss(data);

    while (ss >> num)
    {
        if (num % 2 == 0)
        {
            appendNewNode(num);
        }
        else
        {
            insertNodeAtFront(num);
        }
    }
    printList(head);
    return 0;
}