#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

int isEmpty();
int isFull();
struct node *push(int x);
int pop();

int M, N;
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
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf(" %d ", Adj[i][j]);
        }
        printf("\n");
    }
}

void DFS(int array[][N + 1], int n)
{
    int visited[n], v;
    printf("Enter vertex: ");
    scanf("%d", &v);

    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    visited[v] = 1;
    push(v);

    do
    {
        for (int j = 0; j < n; j++)
        {
            if (array[v][j] == 1 && visited[j] == 0)
            {
                push(j);
            }
        }
            printf(" %d ", v);
            visited[v] = 1;
            v = pop();
    

    } while (!isEmpty());
}

int main()
{
    N = 7;

    int inputGraph[][2] = {{1, 4}, {0, 2}, {1, 2}, {2, 3}, {4, 5}, {0, 6}};

    M = sizeof(inputGraph) / sizeof(inputGraph[0]);

    int AdjacencyMatrix[N + 1][N + 1];

    createAdjacencyMatrix(AdjacencyMatrix, inputGraph);
    showAdjacencyMatrix(AdjacencyMatrix);
    DFS(AdjacencyMatrix, N);
}

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