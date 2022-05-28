#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void printLinkedList(struct node *ptr)
{

    while (ptr != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

struct node *createLinkedList(struct node *head, int data)
{
    head = (struct node *)malloc(sizeof(struct node));

    head->data = data;
    head->next = NULL;
    printf("\nlinklist successfully created\n");
    return head;
}

void insertNode(struct node *head, int data)
{

    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));

    ptr->data = data;
    ptr->next = NULL;

    struct node *p = head;


    while (p->next != NULL)
    {
        p = p->next;

    }

    p->next = ptr;
    ptr->next = NULL;
    printf("Node successfully inserted\n");

}

void deleteAfterIndex(struct node *head, int index)
{
    struct node *p = head;
    struct node *q = head->next;

    for (int i = 1; i < index; i++)
    {
        p = p->next;
        q = q->next;
    }

    p->next = q->next;
    free(q);
}

struct node * concatinate(struct node *head1, struct node *head2){
    struct node *p = head1;
    struct node *q = head2;

    while(p->next != NULL){
        p = p->next;
    }

    p->next = q;
    return head1;
}

struct node * revertLinklist(struct node *head){
    struct node * current = head;
    struct node * previous = NULL;
    struct node * temp;

    while(current != NULL){
        temp = current->next;
        
        current->next = previous;
        previous = current;
        current = temp;
    }

    return previous;
}

int main(){

    struct node *list1;
    list1 = createLinkedList(list1, 9);
    insertNode(list1, 8);
    insertNode(list1, 7);
    insertNode(list1, 6);
    insertNode(list1, 5);
    insertNode(list1, 4);

    printf("\nDisplay the inserted linklist is:\n");
    printLinkedList(list1);

    printf("\nDelete the node after index 2:\n");
    deleteAfterIndex(list1, 2);
    printLinkedList(list1);

    printf("\nReverted  linked list is:\n");
    list1 = revertLinklist(list1);
    printLinkedList(list1);

    printf("\nTo concatinate the string lets create other linked list first:\n");
    struct node *list2;
    list2 = createLinkedList(list2, 20);
    insertNode(list2,19);
    insertNode(list2,18);
    insertNode(list2,17);

    printf("\nOther linked list is:\n");
    printLinkedList(list2);

    printf("\nConctinated list is:\n");
    list1 = concatinate(list1, list2);
    printLinkedList(list1);


}