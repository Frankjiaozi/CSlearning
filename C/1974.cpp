#include <stdio.h>
#include <math.h>
int main()
{
    int a=0,b=0;
    scanf("%d,%d",&a,&b);
for(int i=a;i<=b;i++)
{
    for(int j=i;j<=b;j++)
    {
        for(int t=j;t<=b;t++)
        {
            if(i*i+j*j==t*t) printf("%d^2+%d^2=%d^2\n",i,j,t);
        }
    }   
}
}