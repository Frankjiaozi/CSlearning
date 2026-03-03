#include <stdio.h>
int factorsum(int x)
{   int sum=0;
    for(int i=1;i<x;i++)
    {   
        if(x%i==0) sum+=i;
    }
    return sum;
}
int main()
{   
    int m,n;
    scanf("%d %d",&m,&n);
    for(int i=m;i<=n;i++)
    {
        if(factorsum(i)==i) 
        {
            printf("%d ",i);

        }
    
    }
}