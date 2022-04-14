#include <stdio.h>

int calculatePower(int x, int n)
{
    if (x == 0)
    {
        return 0;
    }

    if (n == 0)
    {
        return 1;
    }

    int power = x * calculatePower(x, n - 1);
    return power;
}
int main()
{
    int result = calculatePower(2, 3);
    printf("%d", result);
}