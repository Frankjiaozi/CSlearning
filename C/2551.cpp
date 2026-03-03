#include <stdio.h>
int factorsum(int x)
{   int sum=0;
    for(int i=1;i<x;i++)
    {
        if(x%i==0) sum=sum+i;
    }
return sum;
}




int main()
{   int m,n;
    while(scanf("%d %d",&m,&n)!=EOF)
    {
        if(factorsum(m)==n&&factorsum(n)==m) printf("Yes\n");
        else printf("No\n");
    }
}
