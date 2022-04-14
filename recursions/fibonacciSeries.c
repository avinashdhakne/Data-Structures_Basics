#include <stdio.h>

int fibonacciSeries(int a, int b, int n)
{
    if (n == 0)
    {
        return 0;
    }
    int result = a + b;
    printf(" %d ", result);
    fibonacciSeries(b , result, n - 1);
}
int main()
{
    int a = 0, b = 1;
    printf("%d %d", a, b);
    int n = 10;
    fibonacciSeries(a, b, n - 2);
}