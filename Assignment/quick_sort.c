#include <stdio.h>

void print_array(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
}

int partition(int array[], int low, int high)
{
    int pivot = array[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (array[i] <= pivot)
        {
            i++;
        }

        while (array[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }

    } while (i < j);

    temp = array[low];
    array[low] = array[j];
    array[j] = temp;

    return j;
}

void quick_sort(int array[], int low, int high)
{
    int partition_index;

    if (low < high)
    {
        int partition_index = partition(array, low, high);
        quick_sort(array, low, partition_index - 1);
        quick_sort(array, partition_index + 1, high);

    }
}

int main()
{
    int array[] = {8, 5, 9, 6, 5, 4, 7, 8, 5, 4};
    int len = sizeof(array) / sizeof(array[0]);

    quick_sort(array, 0, len-1);

    print_array(array, len);
}