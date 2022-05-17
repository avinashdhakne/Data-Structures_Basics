#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node *creatNode(int val)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

int main()
{
    struct node *root;
    root = creatNode(10);
    root->left = creatNode(7);
    root->right = creatNode(9);
    root->left->right = creatNode(21);

    return 0;
}