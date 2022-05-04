#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *f = NULL;
struct node *r = NULL;

int enqueueFront(int val)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));

    if (n == NULL)
    {
        printf("Queue is FUll");
    }

    n->data = val;
    n->prev = NULL;

    if (f == NULL && r == NULL)
    {
        f = r = n;
    }
    else
    {
        n->next = f;
        f->prev = n;
        f = n;
    }

    return val;
}

int enqueueRare(int val)
{

    struct node *n = (struct node *)malloc(sizeof(struct node));
    if (n == NULL)
    {
        printf("Queue is full");
    }

    n->data = val;
    n->next = NULL;

    if (f == NULL && r == NULL)
    {
        f = r = n;
    }
    else
    {
        r->next = n;
        n->prev = r;
        r = n;
    }

    return val;
}

int dequeueFront()
{
    int val = -1;
    struct node *ptrF = f;
    if (r == NULL)
    {
        printf("Queue is empty");
    }
    else
    {
        f = f->next;
        f->prev = NULL;
        val = ptrF->data;
        free(ptrF);
    }

    return val;
}

int dequeueRare()
{
    int val = -1;
    struct node *ptrR = r;

    if (r == NULL)
    {
        printf("Queue is empty");
    }
    else
    {
        r = r->prev;
        r->next = NULL;
        val = ptrR->data;
        free(ptrR);
    }

    return val;
}

void printqueue()
{
    struct node *print = f;
    while (print != NULL)
    {
        printf("%d\t", print->data);
        print = print->next;
    }
}

int main()
{
    printf("enqueue element to front: %d\n",enqueueFront(30));
    printf("enqueue element to front: %d\n",enqueueFront(40));
    printf("enqueue element to Rare: %d\n",enqueueRare(50));
    printf("enqueue element to Rare: %d\n",enqueueRare(60)); 
    printf("\nprint Queue \n");
    printqueue();

    printf("\n\nDequeueing the elements\n");
    printf("dequed element from rare: %d \n", dequeueRare());
    printf("dequed element from front: %d \n", dequeueRare());

    printf("\nprint Queue \n");
    printqueue();
}