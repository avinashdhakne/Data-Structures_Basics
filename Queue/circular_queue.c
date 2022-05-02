/*--- source tutorials point https://www.javatpoint.com/circular-queue*/
#include <stdio.h>
#include <stdlib.h>

struct circular_queue
{
    int size;
    int f;
    int r;
    int *array;
};

int isEmpty(struct circular_queue *q)
{
    if (q->f == -1 && q->r == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(struct circular_queue *q)
{
    if ((q->r + 1) % q->size == q->f)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct circular_queue *q, int val)
{
    if (isEmpty(q))
    {
        q->f = q->r = 0;
        q->array[q->r] = val;
        printf("enqueue %d \n", val);
    }

    else if (isFull(q))
    {
        printf("Queue is full \n");
    }

    else
    {
        q->r = (q->r + 1) % q->size;
        q->array[q->r] = val;
        printf("enqueue %d \n", val);
    }
}

void dequeue(struct circular_queue *q)
{
    if (isEmpty(q))
    {
        printf("queue is empty \n");
    }

    else if (q->r == q->f)
    {
        printf("dequeue element %d \n", q->array[q->f]);
        q->f = q->r = -1;
    }

    else
    {
        q->f = (q->f + 1) % q->size;
        printf("dequeue element %d \n", q->array[q->f]);
    }
}

int main()
{
    struct circular_queue q;
    q.f = q.r = -1;
    q.size = 4;
    q.array = (int*) malloc(q.size * sizeof(int));

    printf("queue is empty %d \n", isEmpty(&q));
    printf("queue is full %d \n", isFull(&q));

    enqueue(&q, 10);
    enqueue(&q, 15);
    enqueue(&q, 35);
    enqueue(&q, 45);

    printf("queue is full %d \n", isFull(&q));
    enqueue(&q, 45);

    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);

    printf("queue is empty %d \n", isEmpty(&q));
    dequeue(&q);





    



}