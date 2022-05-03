#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *f = NULL;
struct node *r = NULL;

int enqueue(int val)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));

    if (n == NULL)
    {
        printf("Queue is full \n");
    }
    else
    {
        n->data = val;
        n->next = NULL;

        if (r == NULL && f == NULL)
        {
            r = f = n;
        }
        else
        {
            r->next = n;
            r = n;
        }
    }

    return val;
}

int dequeue()
{
    int val = -1;
    struct node *ptr = f;
    if (f == NULL)
    {
        printf("Queue is empty \n");
        return -1;
    }

    f = f->next;
    val = ptr->data;
    return val;
}
int main()
{
    printf("enqueue %d \n", enqueue(45));
    printf("enqueue %d \n", enqueue(12));
    printf("enqueue %d \n", enqueue(15));
    printf("dequeue %d \n", dequeue());
    printf("dequeue %d \n", dequeue());
    printf("dequeue %d \n", dequeue());
    printf("dequeue %d \n", dequeue());


}