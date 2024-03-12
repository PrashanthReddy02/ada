#include<stdio.h>
#include<stdlib.h>
int n,c[20][20],visited[10],a,b,cost;
void prim();
void main()
{
    printf("enter the no. of vertices: \n");
    scanf("%d",&n);
    printf("enter the cost matrix :\n");
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&c[i][j]);
            visited[i]=0;
        }
    }
    prim();
}
void prim()
{
    int min=999;
    int count=0;
    visited[1]=1;
    while(count<n-1)
    {
        min=999;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(visited[i]&&!visited[j]&&min>c[i][j])
                {
                    min=c[i][j];
                    a=i;
                    b=j;
                }
            }
        }
        printf("%d-->%d=%d",a,b,c[a][b]);
        cost=cost+c[a][b];
        visited[b]=1;
        count++;
    }
    printf("min cost =%d\n",cost);
}