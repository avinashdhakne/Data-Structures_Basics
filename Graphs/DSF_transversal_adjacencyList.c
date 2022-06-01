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

struct node *top = NULL;

void printstack(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf(" %d ", ptr->data);
        ptr = ptr->next;
    }
}

int isEmpty()
{
    if (top == NULL)
    {
        return 1;
    }
    return 0;
}

int isFull()
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    if (p == NULL)
        return 1;
    return 0;
}

struct node *push(int x)
{
    if (isFull())
    {
        printf("stack overflow");
    }
    else
    {
        struct node *n = (struct node *)malloc(sizeof(struct node));
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
}

int pop()
{
    if (isEmpty())
    {
        printf("stack is empty");
    }
    else
    {
        struct node *n = top;
        top = top->next;
        int x = n->data;
        free(n);
        return x;
    }
}
void DFS(struct graph *graph)
{
    struct adjnode *temp;
    int visited[100], i, v, f;
    for (int i = 0; i < 100; i++)
    {
        visited[i] = 0;
    }

    printf("start vertex: ");
    scanf("%d", &v);
    push(v);
    visited[v] = 1;
    printf(" %d ", v);
    temp = graph->adjlist[v];

    do
    {
        // printf("%d",temp->vertex);
        while (temp != NULL)
        {
            if (visited[temp->vertex] == 0)
            {
                visited[temp->vertex] = 1;
                printf(" %d ", temp->vertex);

                push(temp->vertex);
                v = temp->vertex;
                // break;
            }
            else
            {
                temp = temp->next;
            }
        
        

            if (temp == NULL)
            {
                if (!isEmpty())
                {
                    v = pop();
                    temp = graph->adjlist[v];
                }
            }
        }
        
        
    } while (!isEmpty);
}
int main()
{
    printf("hello");
    struct graph *graph = creategraph(7);
    printf("hello");

    addedge(graph, 0, 1);

    addedge(graph, 1, 4);
    addedge(graph, 0, 2);
    addedge(graph, 1, 2);
    addedge(graph, 2, 3);
    addedge(graph, 4, 5);
    addedge(graph, 0, 6);

    printgraph(graph);

    DFS(graph);
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
};

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
        printf("vertex %d", i);
        while (temp)
        {
            printf("-> %d", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}
