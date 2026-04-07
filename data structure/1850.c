#include <stdio.h>


struct stack
{
    int data[1000];
    int top;
};
typedef struct stack Stack;
void dfs(int pos,Stack s,int path[],int n,int arr[],int index)//123
{

    if(index==n)
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

        return ;
    }
    
    if(s.top>=0)
    {
        path[index] = s.data[s.top];
        s.top--;
        dfs(pos,s,path,n,arr,index+1);
        s.top++;
    }
    if(pos<n)//123
    {
        s.top++;
        s.data[s.top]  = arr[pos];
        dfs(pos+1,s,path,n,arr,index);
        s.top--;
    }

}


int main()
{
    int n;
    
    while(scanf("%d",&n)!=EOF)
    {
        int arr[1000];
    int path[1000];
    Stack s;
    s.top=-1;
    int index=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }

        dfs(0,s,path,n,arr,index);
    }
}

