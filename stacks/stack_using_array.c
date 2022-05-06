#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
}s;

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        printf("stack is empty");
    }
    printf("stack is not empty");

}

void isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        printf("stack is full");
    }
    printf("stack is not full");

}

int main()
{

    struct stack s;

    s.size = 50;
    s.top = -1;
    s.arr = (int *) malloc(s.size * sizeof(int));

    isEmpty(&s);

    s.top = 0;
    s.arr[s.top] = 25;

    isEmpty(&s);
}