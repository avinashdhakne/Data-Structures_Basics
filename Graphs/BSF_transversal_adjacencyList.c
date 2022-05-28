#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct adjnode
{
    int vertex;
    struct adjnode *next;
};

struct graph
{
    int vertises;
    struct adjnode **adjlist;
};

struct adjnode *createnode(int v);
struct graph *creategraph(int vertises);
void addedge(struct graph *graph, int s, int d);
void printgraph(struct graph *graph);

struct node *f = NULL;
struct node *r = NULL;

int isEmpty()
{
    if (f == NULL)
        return 1;
    return 0;
}

int isFull()
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
        return 1;
    return 0;
}

void enqueue(int data)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if (isFull())
        printf("queue is full");
    else
    {
        n->data = data;
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
}

int dequeue()
{
    int val;
    struct node *ptr = f;
    if (isEmpty())
        printf("Queue is empty");
    else
    {
        if (f == r)
        {
            f = r = NULL;
        }
        else
        {
            f = f->next;
        }
        val = ptr->data;
        free(ptr);
    }
    return val;
}

void BFS(struct graph *graph)
{
    int v, visited[graph->vertises];
    struct adjnode *temp;

    for (int i = 0; i < graph->vertises; i++)
    {
        visited[i] = 0;
    }

    printf("Enter the starting vertex:");
    scanf("%d", &v);

    enqueue(v);
    visited[v] = 1;

    while (!isEmpty())
    {
        v = dequeue();
        printf(" %d ", v);
        temp = graph->adjlist[v];
        while (temp != NULL)
        {
            if (visited[temp->vertex] == 0)
            {
                visited[temp->vertex] = 1;
                enqueue(temp->vertex);
                
            }
            temp = temp->next;
        }
  
    }
}

void printqueue()
{
    struct node *print = f;
    while (print != NULL)
    {
        printf("|%d|\t", print->data);
        print = print->next;
    }
}

int main()
{
    struct graph *graph = creategraph(5);
    addedge(graph, 0, 1);
    addedge(graph, 1, 4);
    addedge(graph, 0, 2);
    addedge(graph, 1, 2);
    addedge(graph, 2, 3);

    

    printgraph(graph);
    BFS(graph);

    return 0;
}

struct adjnode *createnode(int v)
{
    struct adjnode *newnode = malloc(sizeof(struct adjnode));
    newnode->vertex = v;
    newnode->next = NULL;
    return newnode;
}

struct graph *creategraph(int vertises)
{
    struct graph *newgraph = (struct graph *)malloc(sizeof(struct graph));
    newgraph->vertises = vertises;
    newgraph->adjlist = (struct graph *)malloc(vertises * sizeof(struct graph));

    for (int i = 0; i < vertises; i++)
    {
        newgraph->adjlist[i] = 0;
    }

    return newgraph;
}

void addedge(struct graph *graph, int s, int d)
{
    struct adjnode *newnode = createnode(d);
    newnode->next = graph->adjlist[s];
    graph->adjlist[s] = newnode;

    newnode = createnode(s);
    newnode->next = graph->adjlist[d];
    graph->adjlist[d] = newnode;
}

void printgraph(struct graph *graph)
{
    for (int i = 0; i < graph->vertises; i++)
    {
        struct adjnode *temp = graph->adjlist[i];
        printf("vertex %d ", i);
        while (temp)
        {
            printf("-> %d", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}