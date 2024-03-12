#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int merge(int a[], int low, int high)
{
    int pivot = a[high];
    int i = (low - 1);

    for (int j = low; j <= high; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[high]);
    return (i + 1);
}

void quickSort(int a[], int low, int high)
{

    if (low < high)
    {
        int pi = merge(a, low, high);
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    clock_t start, end;

    int n;
    printf("Enter size of array:");
    scanf("%d", &n);
    int a[n];
    printf("enter elements:\n");
    for (int i = 0; i < n; i++)
    {
       scanf("%d",&a[i]);
    }
    printf("\ninitial array:");
    printArray(a, n);
    start = clock();
    quickSort(a, 0, n);
    end = clock();
    printf("\nsorted array:");
    printArray(a, n);

    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\ntime taken for sorting : %f sec", time_spent);
    return 0;
}
