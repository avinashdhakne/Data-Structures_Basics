// reference : https://www.geeksforgeeks.org/graph-and-its-representations/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int dest;
    struct node *next;
};

struct adjList
{
    struct node *head;
};

struct graph
{
    int vertex;
    struct adjList *array;
};

struct node *createNode(int dest)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->dest = dest;
    newNode->next = NULL;

    return newNode;
}

struct graph *createGraph(int v)
{
    struct graph *newGraph = (struct graph *)malloc(sizeof(struct graph));
    newGraph->vertex = v;
    newGraph->array = (struct adjList *)malloc(v * sizeof(struct adjList));

    for (int i = 0; i < newGraph->vertex; i++)
    {
        newGraph->array[i].head = NULL;
    }
    return newGraph;
}

void addEdge(struct graph *graph, int src, int dest)
{
    struct node *temp = NULL;
    struct node *newnode = createNode(dest);

    if (graph->array[src].head == NULL)
    {
        newnode->next = graph->array[src].head;
        graph->array[src].head = newnode;
    }
    else
    {
        temp = graph->array[src].head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }

    newnode = createNode(src);
    if (graph->array[dest].head == NULL)
    {
        newnode->next = graph->array[dest].head;
        graph->array[dest].head = newnode;
    }
    else
    {
        temp = graph->array[dest].head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void printGraph(struct graph *graph){
    for(int i=0; i<graph->vertex; i++){
        struct node *tempgraph = graph->array[i].head;
        printf("vertex %d ", i) ;
        while(tempgraph){
            printf("-> %d", tempgraph->dest);
            tempgraph = tempgraph->next;
        }
        printf("\n");
    }
}
int main()
{
    struct graph *graph = createGraph(5);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printGraph(graph);

}