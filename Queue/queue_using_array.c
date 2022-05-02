#include<stdio.h>
#include<stdlib.h>

struct Queue
{
    int size;
    int f;
    int r;
    int *array;
};

int isEmpty(struct Queue *q){
    if (q->f == q->r){
        return 1;
    }
    return 0;
}

int isFull(struct Queue *q){
    if (q->f == q->size-1){
        return 1;
    }
    return 0;
}

int  enqueue(struct Queue *q, int val){
    if(isFull(q)){
        printf("Queue is already full");
        return -1;
    }
    else {
        q->f = q->f+1;
        q->array[q->f] = val;
        return val;
    }
}

int dequeue(struct  Queue *q){
    int a = -1;
    if (isEmpty(q)){
        printf("Queue is already empty");
        return -1;
    }

    q->r = q->r+1;
    return q->array[q->r];
}


int main(){
    struct Queue q;
    q.f = q.r = -1;
    q.size = 100;
    q.array = (int*) malloc (q.size * sizeof(int));

    printf("is empty %d \n", isEmpty(&q));
    printf("enqueue %d \n", enqueue(&q, 15));
    printf("enqueue %d \n", enqueue(&q, 20));
    printf("dequeue %d \n", dequeue(&q));
    printf("dequeue %d \n", dequeue(&q));
    printf("is empty %d \n", isEmpty(&q));
    printf("dequeue %d \n", dequeue(&q));






}