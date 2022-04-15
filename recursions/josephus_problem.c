#include <stdio.h>

int josephus(int n, int k)
{
    if (n == 1 || k == 0)
    {
        return 0;
    }
    return (josephus(n - 1, k) + k) % n;
}
int main()
{
    int result = josephus(5, 3);
    printf("%d", result);
}