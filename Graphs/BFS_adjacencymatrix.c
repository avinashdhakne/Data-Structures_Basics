#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *f = NULL;
struct node *r = NULL;

int M, N;

int isEmpty();
int isFull();
void enqueue(int data);
int dequeue();

void createAdjacencyMatrix(int Adj[][N + 1], int arr[][2])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            Adj[i][j] = 0;
        }
    }

    for (int i = 0; i < M; i++)
    {
        int x = arr[i][0];
        int y = arr[i][1];

        Adj[x][y] = 1;
        Adj[y][x] = 1;
    }
}

void showAdjacencyMatrix(int Adj[][N + 1])
{
    for (int i = 0; i < N ; i++)
    {
        for (int j = 0; j < N ; j++)
        {
            printf(" %d ", Adj[i][j]);
        }
        printf("\n");
    }
}

void BFS(int array[][N + 1], int n)
{
    int visited[n],v;
    printf("Enter vertex: ");
    scanf("%d", &v);
   
    for(int i=0; i<n;i++){
        visited[i] = 0;
    }

    printf("%d ", v);
    visited[v] = 1;
    enqueue(v); 
    
    while (!isEmpty())
    {
        int node = dequeue();
        // printf("%d", node);

        for (int j = 0; j < n; j++)
        {
            // printf("hello");
            if (array[node][j] == 1 && visited[j] == 0)
            {
                printf(" %d ", j);
                visited[j] = 1;
                enqueue(j);
            }
        }
    }
}



int main()
{
    N = 7;

    int inputGraph[][2] = {{1, 4}, {0, 2}, {1, 2}, {2, 3}, {4, 5}, {0, 6}};

    M = sizeof(inputGraph) / sizeof(inputGraph[0]);

    int AdjacencyMatrix[N + 1][N + 1];

    createAdjacencyMatrix(AdjacencyMatrix, inputGraph);
    showAdjacencyMatrix(AdjacencyMatrix);

    BFS(AdjacencyMatrix, N);
}

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

void printqueue()
{
    struct node *print = f;
    while (print != NULL)
    {
        printf("|%d|\t", print->data);
        print = print->next;
    }
}