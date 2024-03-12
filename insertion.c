#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int sort(int n, int a[]);
void print_array(int a[], int size);
int main()
{
    clock_t start, end;
    int n;
    printf("Enter size of array:");
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\ninitial array:");
    print_array(a, n);
    start = clock();
    sort(n, a);
    printf("\nsorted array:");
    print_array(a, n);
    end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\ntime taken for sorting : %f sec", time_spent);
}
int sort(int n, int a[])
{
    int key,j;
    for (int i = 1; i <= n; i++)
    {
        key = a[i];
        j=i-1;
         while (j >= 0 && a[j] > key) 
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
       
    }
}
void print_array(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", a[i]);
    }
}
