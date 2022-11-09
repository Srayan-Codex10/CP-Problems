#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

// doubly-linked
typedef struct node
{

    int data;
    node *next;
} Node;

Node *front = NULL, *rear = NULL;

Node *createNode(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void enqueue(int data)
{
    Node *newNode = createNode(data);
    if (NULL == front && NULL == rear)
    {
        front = newNode;
        rear = front;
        return;
    }

    rear->next = newNode;
    rear = newNode;
}

void dequeue()
{
    if (NULL == front && NULL == rear)
    {
        cout << "Queue Empty"
             << "\n";
        return;
    }
    Node *deq = front;
    front = front->next;
    free(deq);
}

void printQueue()
{
    Node *temp = front;
    if (NULL == temp)
    {
        cout << "Empty Queue" << endl;
        return;
    }
    cout << "Data: ";
    while (temp)
    {
        cout << temp->data << "\t";
        temp = temp->next;
    }
}

string readData()
{
    string line;
    fstream file;
    file.open("../C++/input.txt", ios::in);
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
    string line = readData();
    int num;
    string data;
    stringstream ss(line);

    while (ss >> num)
    {
        enqueue(num);
    }
    dequeue();
    dequeue();
    printQueue();
}