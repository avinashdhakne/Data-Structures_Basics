#include <stdio.h>
#include <stdlib.h>

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
int main()
{
struct graph* graph = creategraph(4);
  addedge(graph, 0, 1);
  addedge(graph, 0, 2);
  addedge(graph, 0, 3);
  addedge(graph, 1, 2);

  printgraph(graph);

  return 0;
}