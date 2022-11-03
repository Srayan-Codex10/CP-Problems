#include <iostream>
using namespace std;

typedef struct node
{
    int data;
    node *next;
    node *prev;
} Node;
Node *rear, *front;

Node *create_node(int val)
{
    Node *link;
    link = (Node *)malloc(sizeof(Node));
    link->data = val;
    link->next = NULL;
    link->prev = NULL;
    return link;
}

void insert_node(int x)
{
    Node *temp = create_node(x);
    if (rear == NULL && front == NULL)
    {
        front = temp;
        rear = temp;
        // temp->prev = front;
        // temp->next = rear;
    }
    else
    {
        temp->prev = rear;
        rear->next = temp;
        rear = temp;
        // temp->next = rear;
    }
}

void print_list(Node *root)
{
    Node *temp;
    temp = root;
    while (temp != NULL)
    {
        cout << temp->data << ' ';
        temp = temp->next;
    }
}

void reverse_print_list(Node *root)
{
    Node *temp;
    temp = root;
    while (temp != NULL)
    {
        cout << temp->data << ' ';
        temp = temp->prev;
    }
}

int main()
{
    rear = front = NULL;
    int data, size;
    cout << "Enter size of list: " << endl;
    cin >> size;
    cin.sync();
    for (int i = 0; i < size; i++)
    {

        cout << "Enter node value: " << endl;
        cin >> data;
        insert_node(data);
    }
    cout << "LinkedList -> ";
    print_list(front);
    reverse_print_list(rear);
}