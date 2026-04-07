#include <stdio.h>

void dfs(int x,int path[],int arr[],int used[],int n)
{
    if(x==n)
    {
        for(int i=0;i<n;i++)
        {
            printf("%d",path[i]);
            if(i!=n-1)
            {
                printf(" ");
            }
        }
        printf("\n");
        return;
    }
    for(int i=0;i<n;i++)//123
                        //100
    {
        if(used[i]==0)
        {
            path[x] = arr[i];
            used[i]=1;
            dfs(x+1,path,arr,used,n);
            used[i]=0;
        }
        
    }

}

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
int path[100]={0};
int arr[100]={0};
int used[100]={0};
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    dfs(0,path,arr,used,n);
    }
    
}