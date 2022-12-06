#include <iostream>

using namespace std;

typedef struct tnode
{

    int data;
    tnode *left;
    tnode *right;

} Tn;

Tn *root;

Tn *createTreeNode(int v)
{

    Tn *tv = (Tn *)malloc(sizeof(Tn));
    tv->data = v;
    tv->left = NULL;
    tv->right = NULL;
    return tv;
}

Tn *addChild(bool l, bool r, Tn *p, int data)
{

    if (l)
    {
        p->left = createTreeNode(data);
        return p;
    }

    if (r)
    {
        p->right = createTreeNode(data);
        return p;
    }

    return p;
}

void printTree(Tn *t)
{

    if (t)
    {
        cout << t->data << "\t";
        printTree(t->left);
        printTree(t->right);
    }
}

int h(Tn *t)
{

    if (t->left == NULL && t->right == NULL)
    {
        return 1;
    }
    else if (t->left == NULL && t->right != NULL)
    {
        return 1 + h(t->right);
    }
    else if (t->left != NULL && t->right == NULL)
    {
        return 1 + h(t->left);
    }

    return h(t->left) + h(t->right) + 1;
}

int main()
{
    root = createTreeNode(30);
    root->left = createTreeNode(20);
    // root->right = createTreeNode(60);
    // root->left->left = createTreeNode(10);
    // root->left->right = createTreeNode(30);
    // root->right->left = createTreeNode(22);
    printTree(root);
    cout << "\n";
    cout << h(root);
}