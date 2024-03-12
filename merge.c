#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void merge(int arr[], int left[], int right[], int left_len, int right_len)

{
    int i = 0, j = 0, k = 0;
    while (i < left_len && j < right_len)
    {
        if (left[i] < right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < left_len)
    {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < right_len)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int arr_len)

{
    if (arr_len <= 1)
    {
        return;
    }
    int mid = arr_len / 2;
    int left[mid];
    int right[arr_len - mid];
    for (int i = 0; i < mid; i++)
    {
        left[i] = arr[i];
    }
    for (int i = mid; i < arr_len; i++)
    {
        right[i - mid] = arr[i];
    }
    mergeSort(left, mid);
    mergeSort(right, arr_len - mid);

    merge(arr, left, right, mid, arr_len - mid);
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
    mergeSort(a, n);
    printf("\nsorted array:");
    printArray(a, n);
    end = clock();
    

    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\ntime taken for sorting : %f sec", time_spent);
    return 0;
}
