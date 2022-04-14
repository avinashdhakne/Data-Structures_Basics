#include <stdio.h>

int nonZero(int row, int col, int matrix[row][col])
{
    int nonZero;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] != 0)
            {
                nonZero++;
            }
        }
    }
    return nonZero;
}

int SparseRepresentation(int row, int col, int max, int matrix[row][col], int sparse[max][3])
{

    int sparse_row = 1;
    sparse[0][0] = row;
    sparse[0][1] = col;
    sparse[0][2] = max - 1;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] != 0)
            {
                sparse[sparse_row][0] = i;
                sparse[sparse_row][1] = j;
                sparse[sparse_row][2] = matrix[i][j];
                sparse_row++;
            }
        }
    }
}

void SimpleTranspose(int row, int col, int max, int matrix[row][col], int sparse[max][3], int simple[max][3])
{
    int fast_row = 1;
    simple[0][0] = sparse[0][1];
    simple[0][1] = sparse[0][0];
    simple[0][2] = max - 1;

    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < max; j++)
        {
            if (sparse[j][1] == i)
            {
                simple[fast_row][0] = sparse[j][1];
                simple[fast_row][1] = sparse[j][0];
                simple[fast_row][2] = sparse[j][2];
                fast_row++;
            }
        }
    }
}

void FastTranspose(int row, int col, int max, int matrix[col][row], int sparse[max][3], int fast[max][3])
{
    int index[col + 1], total[col];

    for (int i = 0; i < col; i++)
    {
        int count = 0;

        for (int j = 0; j < row; j++)
        {
            if (matrix[j][i] != 0)
            {
                count++;
            }
        }
        total[i] = count;
    }

    index[0] = 1;
    for (int i = 1; i < (col + 1); i++)
    {
        index[i] = index[i - 1] + total[i - 1];
    }

    fast[0][0] = sparse[0][1];
    fast[0][1] = sparse[0][0];
    fast[0][2] = sparse[0][2];

    for (int i = 1; i < max; i++)
    {
        int num1 = sparse[i][1];
        int num2 = index[num1];
        index[num1] = num2+1;

        fast[num2][0] = sparse[i][1];
        fast[num2][1] = sparse[i][0];
        fast[num2][2] = sparse[i][2];
    }
}

int main()
{
    int row, col;
    printf("Enter the row in Sparce matrix: ");
    scanf("%d", &row);
    printf("Enter the columns in Sparce matrix: ");
    scanf("%d", &col);

    int matrix[row][col];
    for (int i = 0; i < row; i++)
    {
        printf("Enter the element in row %d: ", i + 1);
        for (int j = 0; j < col; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
        printf("\n");
    }

    int num = nonZero(row, col, matrix);
    int max = num + 1;

    printf("Sparce representaion of matrix is: \n");

    int sparse[num][3];
    SparseRepresentation(row, col, max, matrix, sparse);

    for (int i = 0; i < max; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d\t", sparse[i][j]);
        }
        printf("\n");
    }

    printf("Simple transpose of sparce  of matrix is: \n");

    int simple[max][3];
    SimpleTranspose(row, col, max, matrix, sparse, simple);

    for (int i = 0; i < max; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d\t", simple[i][j]);
        }
        printf("\n");
    }

    printf("Fast Transpose of sparse matrix is: \n");

    int fast[max][3];
    FastTranspose(row, col, max, matrix, sparse, fast);

    for (int i = 0; i < max; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d\t", fast[i][j]);
        }
        printf("\n");
    }
    
}
