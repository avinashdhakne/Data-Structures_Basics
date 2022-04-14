#include <stdio.h>

int printnum(int num){
    printf("run");
    if (num == 0){
        printf("%d",num);
        return num;
    }
    printf("- %d\n",num);
    printnum(num-1);
}
int main()
{
    printnum(5);
}