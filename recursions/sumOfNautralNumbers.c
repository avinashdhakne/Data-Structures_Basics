#include <stdio.h>

void sumNauralNumbers(int i, int n, int sum){

    if (i == n){
        sum += n;
        printf("%d", sum);
    }
    sum += i;
    sumNauralNumbers(i+1, n, sum);
}
int main(){
    sumNauralNumbers(1, 5, 0);
}