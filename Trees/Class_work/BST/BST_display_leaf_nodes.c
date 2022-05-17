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

void showLeafNode(struct node *root)
{
    if(root==NULL){
        return;
    }
    showLeafNode(root->left);
    showLeafNode(root->right);
    if(root->left == NULL && root->right == NULL){
        printf("%d\t", root->data);
    }
}
int main()
{
    struct node *root = NULL;
    root = insert(root, 15);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 85);
    root = insert(root, 60);
    root = insert(root, 28);
    root = insert(root, 8);
    root = insert(root, 17);



    inorderTraversal(root);
    printf("\nleaf nodes: ");
    showLeafNode(root);
    return 0;
}