#include <stdio.h>

struct student
{
    int roll_no;
    int marks;
} st;

void print_array(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
}

void print_struct(struct student array[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("information of student %d: \t", i + 1);
        printf("Roll no: %d Mark: %d\n", array[i].roll_no, array[i].marks);
    }
    printf("\n");
}

void bubble_sort(struct student array[], int n)
{
    struct student temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < (n - 1 - i); j++)
        {
            if (array[j].roll_no > array[j + 1].roll_no)
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
            else
            {
                continue;
            }
        }
    }
}

int partition(struct student array[], int low, int high)
{
    int pivot = array[low].roll_no;
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (array[i].roll_no <= pivot)
        {
            i++;
        }

        while (array[j].roll_no > pivot)
        {
            j--;
        }

        if (i < j)
        {
            temp = array[i].roll_no;
            array[i].roll_no = array[j].roll_no;
            array[j].roll_no = temp;
        }

    } while (i < j);

    temp = array[low].roll_no;
    array[low].roll_no = array[j].roll_no;
    array[j].roll_no = temp;

    return j;
}

void quick_sort(struct student array[], int low, int high)
{
    int partition_index;

    if (low < high)
    {
        int partition_index = partition(array, low, high);
        quick_sort(array, low, partition_index - 1);
        quick_sort(array, partition_index + 1, high);
    }
}

void heapify(struct student array[], int n, int i)
{

    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    struct student temp;

    if (left < n && array[left].roll_no > array[largest].roll_no)
        largest = left;

    if (right < n && array[right].roll_no > array[largest].roll_no)
        largest = right;

    if (largest != i)
    {
        temp.roll_no = array[i].roll_no;
        array[i].roll_no = array[largest].roll_no;
        array[largest].roll_no = temp.roll_no;
        heapify(array, n, largest);
    }
}

void heap_sort(struct student array[], int n)
{
    struct student temp;
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(array, n, i);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        temp.roll_no = array[0].roll_no;
        array[0].roll_no = array[i].roll_no;
        array[i].roll_no = temp.roll_no;

        heapify(array, i, 0);
    }
}

int binary_search(struct student array[], int len, int num)
{
    int low, high, mid;
    low = 0;
    high = len - 1;

    while (low < high)
    {
        mid = (low + high) / 2;

        if (array[mid].roll_no == num)
        {
            return mid;
        }

        if (array[mid].roll_no > num)
        {
            high = mid - 1;
        }

        if (array[mid].roll_no < num)
        {
            low = mid + 1;
        }
    }

    return -1;
}

int main()
{
    int num, rnum, result;
    printf("Enter no of students:");
    scanf("%d", &num);

    struct student st[num];

    for (int i = 0; i < num; i++)
    {
        printf("Enter the information of student %d: \t", i + 1);
        scanf("%d %d", &st[i].roll_no, &st[i].marks);
    }
    printf("\n");

    printf("You have entered the information as:\n");
    print_struct(st, num);

    printf("Sorted structure accourding to roll no using bubble sort:\n");
    bubble_sort(st, num);
    print_struct(st, num);

    printf("Sorted structure accourding to roll no using quick sort:\n");
    quick_sort(st, 0, num - 1);
    print_struct(st, num);

    printf("Sorted structure accourding to roll no using heap sort:\n");
    heap_sort(st, num);
    print_struct(st, num);

    printf("Enter the roll no of student to search him: ");
    scanf("%d", &rnum);
    result = binary_search(st, num, rnum);
    
    if (result == -1)
    {
        printf("Entered No. is not found");
    }
    else
    {
        printf("Roll no is at index: %d", result);
    }
    printf("\n");
}