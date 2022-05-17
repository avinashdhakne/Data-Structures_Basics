#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node *creatNode(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

struct node *insert(struct node *root, int data)
{
    if (root == NULL)
    {
        root = creatNode(data);
    }

    else if (root->data > data)
    {
        root->left = insert(root->left, data);
    }

    else
    {
        root->right = insert(root->right, data);
    }

    return root;
}

int findMin(struct node *root)
{
    struct node *temp = root;
    if (temp == NULL)
    {
        return -1;
    }

    while (temp->left != NULL)
    {
        temp = temp->left;
    }

    return temp->data;
}

int findMinRecursion(struct node *root)
{
    struct node *temp = root;
    if (temp == NULL)
    {
        return -1;
    }
    else if (temp->left == NULL)
    {
        return temp->data;
    }

    return findMinRecursion(temp->left);
}

int findMax(struct node *root)
{
    struct node *temp = root;
    if (temp == NULL)
    {
        return -1;
    }
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp->data;
}

int findMaxRecursion(struct node *root)
{
    struct node *temp = root;
    if (temp == NULL)
    {
        return -1;
    }
    else if (temp->right == NULL)
    {
        return temp->data;
    }

    return findMaxRecursion(temp->right);
}

int findHeight(struct node *root){
    struct node *temp = root;

    if(temp==NULL){
        return -1;
    }
    
    return max(findHeight(root->left),findHeight(root->right)) + 1;
}

int max(int num1, int num2)
{
    return (num1 > num2 ) ? num1 : num2;
}

int main()
{
    struct node *root = NULL;
    root = insert(root, 17);
    root = insert(root, 12);
    root = insert(root, 6);
    root = insert(root, 15);
    root = insert(root, 14);
    root = insert(root, 25);
    root = insert(root, 45);
    root = insert(root, 30);
    root = insert(root, 40);

    printf("Min value in tree %d\n", findMin(root));
    printf("Min value in tree using recursion %d\n", findMinRecursion(root));
    printf("Max value in tree %d\n", findMax(root));
    printf("Max value in tree using recursions %d \n", findMaxRecursion(root));
    printf("Height of tree %d", findHeight(root));
    return 0;
}