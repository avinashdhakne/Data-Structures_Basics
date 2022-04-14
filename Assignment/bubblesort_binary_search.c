#include <stdio.h>

void print_array(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
}

void swap_array_number(int array[], int i, int j)
{
    int temp;

    temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

int binary_search(int array[], int len, int num){
    int low, high, mid;
    low = 0;
    high = len-1;
    
    while(low < high){
        mid = (low+high)/2;

        if(array[mid]==num){
            return mid;
        }

        if(array[mid]>num){
            high = mid-1;
        }

        if(array[mid]<num){
            low = mid+1;
        }
    }

    return -1;

}
void bubble_sort(int array[], int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap_array_number(array,j,j+1);
            }
            else
            {
                continue;
            }
        }
    }
}

int main()
{

    int array[] = {8, 5, 9, 6, 5, 4, 7, 8, 5, 4};
    int len = sizeof(array) / sizeof(array[0]);
    int num = 3;
    bubble_sort(array, len);

    int result = binary_search(array, len, num);
    printf("%d", result);

    print_array(array, len);
}