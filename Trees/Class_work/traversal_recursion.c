#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *right, *left;
};

struct node *creatNode(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

void preorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }

    printf("%d \t", root->data);
    preorder(root->left);
    preorder(root->right);
}

void indorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }

    indorder(root->left);
    printf("%d\t", root->data);
    indorder(root->right);
}

void postorder(struct node *root)
{
    if(root == NULL)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    printf("%d\t", root->data);
}
int main()
{

    struct node *root;
    root = creatNode(10);
    root->left = creatNode(7);
    root->right = creatNode(9);
    root->left->right = creatNode(21);
    root->left->right->right = creatNode(40);
    root->right->right = creatNode(30);

    printf("preorder: ");
    preorder(root);

    printf("\ninorder: ");
    indorder(root);

    printf("\npostorder: ");
    postorder(root);

    return 0;
}