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

void printStack()
{
    Node *iterator = top;
    while (iterator != NULL)
    {
        cout << iterator->val << " ";
        iterator = iterator->next;
    }
    cout << endl;
}

int main()
{
    top = NULL;
    int n;
    int data;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> data;
        push(data);
    }
    printStack();

    pop();
    pop();
    push(10);
    printStack();
    return 0;
}