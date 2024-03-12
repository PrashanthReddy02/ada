#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void BFS(int a[20][20],int source,int v[20],int n)
{
    int ans[n];
    ans[0]=source;
    int ind=0;
    int queue[20],f,r,x,k;
    f=0;
    r=-1;
    queue[++r]=source;
    while(f<=r)
    {
        x=queue[f++];
        for(k=1;k<=n;k++)
        {
            if(a[x][k]==1&&v[k]==0)
            {
                queue[++r]=k;
                v[k]=1;
                ans[++ind]=k;
            }
        }
    }
    printf("traversal is:");
    for(int i=0;i<=ind;i++)
    {
        printf("%d\t",ans[i]);
    }
}
void main()
{
    int n,v[20],a[20][20],source;
    clock_t start,end;
    printf("enter the number of nodes:\n");
    scanf("%d",&n);
    printf("enter the adjacenncy matrix:\n");
    for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
    for(int i=1;i<=n;i++)
    {
    v[i]=0;
    }
    printf("enter the source node:\n");
    scanf("%d",&source);
    v[source]=1;
    start=clock();
    BFS(a,source,v,n);
    for(int i=1;i<=n;i++)
    {
        if(v[i]!=0)
        {
            printf("node %d is reachable\n",i);
        }
        else{
            printf("node %d is not reachable\n",i);
        }
    }
     end=clock();
    double time_taken=(double)(end-start)/CLOCKS_PER_SEC;
    printf("time taken =%f\n",time_taken);
}