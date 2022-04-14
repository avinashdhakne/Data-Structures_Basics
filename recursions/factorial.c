#include <stdio.h>

int  factorial(int n)
{
    if (n == 1 || n == 0)
    {
        return 1;
    }
    int result;
    result = factorial(n - 1) * n;
    return result;
}
int main()
{
    int final_result = factorial(5);
    printf("%d", final_result);
}