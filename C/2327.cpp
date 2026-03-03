#include <stdio.h>
int main()
{   int n;
    while(scanf("%d",&n)!=EOF)
    {   int arr[n];
        for(int i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }
    
    for(int i=0;i<n;i++)
    {
        printf("%c",arr[i]^'B');
        if(i==n-1) printf("\n");
    }
    }
}