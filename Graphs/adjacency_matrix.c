#include <stdio.h>
int M, N;

void createAdjacencyMatrix(int Adj[][N + 1], int arr[][2])
{
    Adj[0][0] = 0;
    for (int i = 1; i < N + 1; i++)
    {
        Adj[i][0] = i;
        for (int j = 1; j < N + 1; j++)
        {
            Adj[0][j] = j;
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
    for (int i = 0; i < N + 1; i++)
    {
        for (int j = 0; j < N + 1; j++)
        {
            printf(" %d ", Adj[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    N = 5;

    int inputGraph[][2] = {{1, 2}, {2, 3}, {4, 5}, {1, 5}};

    M = sizeof(inputGraph) / sizeof(inputGraph[0]);

    int AdjacencyMatrix[N + 1][N + 1];

    createAdjacencyMatrix(AdjacencyMatrix, inputGraph);
    showAdjacencyMatrix(AdjacencyMatrix);
}