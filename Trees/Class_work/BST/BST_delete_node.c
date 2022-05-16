#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *right, *left;
};

struct node *createNode(int data)
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
        root = createNode(data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }
    else
    {
        root->left = insert(root->left, data);
    }
    return root;
}

void inorderTraversal(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorderTraversal(root->left);
    printf("%d\t", root->data);
    inorderTraversal(root->right);
}

struct node *inorderPredecessor(struct node *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}
struct node *deleteNode(struct node *root, int val)
{
    struct node *iPre;
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }
    if (val < root->data)
    {
        root->left = deleteNode(root->left, val);
    }
    else if (val > root->data)
    {
        root->right = deleteNode(root->right, val);
    }
    else
    {
        iPre = inorderPredecessor(root);
        root->data = iPre->data;
        root->left = deleteNode(root->left, iPre->data);
    }
    return root;
}
int main()
{
    struct node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 45);
    root = insert(root, 17);
    root = insert(root, 15);
    root = insert(root, 48);
    root = insert(root, 97);
    root = insert(root, 63);
    root = insert(root, 41);

    inorderTraversal(root);
    deleteNode(root, 17);
    printf("\n");
    inorderTraversal(root);
}
