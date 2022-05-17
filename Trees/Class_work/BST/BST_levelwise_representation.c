#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct queue
{
    struct node data;
    struct queue *next;
};

struct queue *f = NULL;
struct queue *r = NULL;

struct node *createNode(int val)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
struct node *insert(struct node *root, int val)
{
    if (root == NULL)
    {
        root = createNode(val);
    }
    else if (val < root->data)
    {
        root->left = insert(root->left, val);
    }
    else
    {
        root->right = insert(root->right, val);
    }
    return root;
}

int isEmpty(struct queue *queue)
{
    if (f == NULL && r == NULL)
    {
        return 1;
    }
    return 0;
}
void enqueue(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    struct queue *n = (struct queue *)malloc(sizeof(struct queue));

    if (n == NULL)
    {
        printf("Queue is full");
    }
    else
    {
        n->data = (*root);
        n->next = NULL;

        if (f == NULL && r == NULL)
        {
            f = r = n;
        }
        else
        {
            r->next = n;
            r = n;
        }
    }
    return;
}

struct node *dequeue()
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    struct queue *ptr = f;
    if (f == NULL)
    {
        printf("Queue is empty");
    }

    else
    {
        f = f->next;
        if (f == NULL)
        {
            r = NULL;
        }
        (*temp) = ptr->data;
        free(ptr);
    }

    return temp;
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

int max(int num1, int num2)
{
    return (num1 > num2) ? num1 : num2;
}
int findHeight(struct node *root)
{
    struct node *temp = root;

    if (temp == NULL)
    {
        return -1;
    }

    return max(findHeight(root->left), findHeight(root->right)) + 1;
}

void printLevels(struct node *root)
{

    struct node *temp;
    if (root == NULL)
    {
        return;
    }

    int hig = findHeight(root) + 1;
    enqueue(root);

    for (int i = 1; i <= hig; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (f != NULL && r != NULL)
            {
                temp = dequeue();
                printf("%d\t", temp->data);
            }

            if (temp->left != NULL)
                enqueue(temp->left);
            if (temp->right != NULL)
                enqueue(temp->right);
        }
        printf("\n");
    }
}
int main()
{
    struct node *root = NULL;

    root = insert(root, 40);
    root = insert(root, 20);
    root = insert(root, 78);
    root = insert(root, 17);
    root = insert(root, 32);
    root = insert(root, 72);
    root = insert(root, 34);

    inorderTraversal(root);

    printf("level:\n");
    printLevels(root);
    return 0;
}