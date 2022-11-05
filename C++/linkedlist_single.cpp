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
    if (NULL == temp)
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
    if (NULL == head)
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
    if (NULL == head)
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
    if (NULL == head)
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

Node *insertAfterNode(int data, Node *head, Node *loc)
{
    if (NULL == head)
    {
        head = createNode(data);
        return head;
    }

    Node *newNode = createNode(data);
    newNode->next = loc->next;
    loc->next = newNode;
    return head;
}

/**
 * Insert before a node when Node address is not given
 */
Node *insertBefore(int pos, int data, Node *head)
{
    if (NULL == head)
    {
        head = createNode(data);
        return head;
    }

    if (pos == 1)
    {
        return insertNodeAtFront(head, data);
    }

    Node *newNode = createNode(data);
    Node *temp = head;

    for (int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

/**
 * Insert before a node when node address is given
 */
Node *insertBeforeNode(int data, Node *head, Node *loc)
{
    if (NULL == head)
    {
        head = createNode(data);
        return head;
    }
    Node *iter = head;
    while (iter->next != loc)
    {
        iter = iter->next;
    }
    Node *newNode = createNode(data);
    newNode->next = loc;
    iter->next = newNode;
    return head;
}

void pop(Node *head)
{

    if (NULL == head)
    {
        cout << "Empty List" << endl;
        return;
    }

    Node *temp = head;
    while (temp->next->next)
    {
        temp = temp->next;
    }
    Node *toDelete = temp->next;
    free(toDelete);
    temp->next = NULL;
}

Node *popFront(Node *head)
{
    if (NULL == head)
    {
        cout << "Empty List" << endl;
        return NULL;
    }
    Node *toDelete = head;
    head = head->next;
    free(toDelete);
    return head;
}

Node *deleteNode(Node *head, Node *loc) {
    if(NULL == head) {
        cout << "Empty List" << endl;
        return head;
    }
    Node *prev = head;
    while(prev->next != loc) {
        prev = prev->next;
    }
    prev->next = loc->next;
    free(loc);
    return head;
}

Node *getNode(int data, Node *head)
{
    Node *temp = head;
    if (NULL == head)
        return NULL;

    while (temp)
    {
        if (data == temp->data)
        {
            return temp;
        }
        else
        {
            temp = temp->next;
        }
    }
    return NULL;
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
    insertBeforeNode(23, head, getNode(0, head));
    insertAfterNode(12, head, getNode(1, head));
    printList(head);
    deleteNode(head, getNode(12, head));
    deleteNode(head, getNode(23, head));
    printList(head);
    return 0;
}