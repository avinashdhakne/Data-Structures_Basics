#include <stdio.h>
#include <string.h>
int palindeom(char *str, int i, int n)
{
    if (i >= n)
    {
        return 1;
    }

    if (str[i] != str[n])
    {
        return 0;
    }

    palindeom(str, i + 1, n - 1);
}
int main()
{
    char str[] = "abba";
    int len = strlen(str);

    int result = palindeom(str, 0, len - 1);
    printf("%d", result);
}