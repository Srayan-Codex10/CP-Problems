#include <iostream>

using namespace std;

typedef struct node
{
    int val = 0;
    node *next = NULL;
} Node;

Node *top;

Node *createNode(int val)
{

    Node *temp = (Node *)malloc(sizeof(Node));
    temp->val = val;
    return temp;
}

void push(int val)
{
    Node *data = createNode(val);
    data->next = top;
    top = data;
}

int pop()
{
    int popped = 0;
    if (top != NULL)
    {
        Node *temp = top;
        top = top->next;
        popped = temp->val;
        free(temp);
    }
    else
    {
        cout << "Underflow" << endl;
    }
    return popped;
}

int main()
{

    top = NULL;

    for (int i = 0; i < 5; i++)
    {
        push(i);
    }

    while (top != NULL)
    {
        cout << top->val << " ";
        top = top->next;
    }

    return 0;
}