#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createnode(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

struct node *insert(struct node *root, int val)
{
    if (root == NULL)
    {
        root = createnode(val);
    }

    else if (root->data > val)
    {
        root->left = insert(root->left, val);
    }
    else
    {
        root->right = insert(root->right, val);
    }

    return root;
}
int main()
{
    struct node *root = NULL;
    root = insert(root, 15);
    root = insert(root, 20);
    root = insert(root, 40);
    return 0;
}