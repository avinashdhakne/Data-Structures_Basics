# include <stdio.h>
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

    int colLocation, rowLocation;
    int flag = 0;

    for (int i = 0; i < col; i++)
    {
        int min = matrix[i][0];
        for (int j = 1; j < row; j++)
        {
            if (matrix[i][j] < min)
            {
                min = matrix[i][j];
                colLocation = j;
            }
        }

        int max = matrix[i][colLocation];
        for (int j = 1; j < col; j++)
        {
            if (matrix[j][colLocation] > max)
            {
                max = matrix[j][colLocation];
                rowLocation = j;
            }
        }
        printf("%d %d\n",min,max);
        if(min == max){
            printf("Saddle point of matrix is: %d at location (%d,%d)", matrix[rowLocation][colLocation], rowLocation,colLocation);
            flag=1;
        }
    }

    if (flag == 0){
        printf("There is no saddle point in matrix");
    }

}