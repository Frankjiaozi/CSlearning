
#include <stdio.h>

long long int power(int a,int b)
{
    long long int s=1;
    for(int i=0;i<b;i++)
    {
        s*=a;
    }
    return s;
}



int main()
{
    long long int n;
    while(scanf("%lld",&n)!=EOF && n!=0)
    {
        int k=1;
        while(1)
        {
            if(power(3,k-1)<=n && n<=power(3,k))
            {
                break;
            }
            k++;
        }
        if(n==1)
        {
            k=0;
        }
        printf("%d\n",k);
    }   
}