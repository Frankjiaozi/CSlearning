#include <stdio.h>

int isprime(int x)
{
    if(x<=1)
    {
        return 0;
    }
    if(x==2)
    {
        return 1;
    }
    for(int i=2;i<x;i++)
    {
        if(x%i==0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int m,n;
    int sum=0;
    scanf("%d %d",&m,&n);
    for(int i=m;i<=n;i++)
    {
        if(isprime(i)==1)
        {
            sum=sum+i;
        }
    }
printf("%d",sum);
}