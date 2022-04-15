/* find the number of ways in n x m matrix */

#include <stdio.h>

int find_ways(int n, int m)
{
    if (m == 1 || n == 1)
    {
        return 1;
    }

    return find_ways(n, m - 1) + find_ways(n - 1, m);
}
int main()
{
    int reuslt = find_ways(2, 3);
    printf("%d", reuslt);
}