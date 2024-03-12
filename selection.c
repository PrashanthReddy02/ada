
#include<stdio.h>
#include<stdlib.h>
int sort(int A[],int n);
int swap(int *,int*);
int main()
{
    int n;
    int A[n];
    printf("enter the size:\n");
    scanf("%d",&n);
    printf("enter the elements:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    printf("before sorting:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d",&A[i]);
    }
    printf("\n");
    sort(A,n);
    printf("after sorting:");
    for(int i=0;i<n;i++)
    {
        printf("%d",&A[i]);
    }

}
int sort(int A[],int n)
{
    int i,j;
    for(i=0;i<=(n-2);i++)
    {
        int min=i;
        for(j=i+1;j<=(n-1);j++)
        {
            if(A[j]<A[min])
            {
                min=j;
            }
        }
        swap(&A[i],&A[min]);
    }
}
int swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
