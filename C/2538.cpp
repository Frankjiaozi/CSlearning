#include <stdio.h>
#include <math.h>
int check_prime(int x)
{   if(x<=1) return 0;
    
    int flag=1;
    for(int i=2;i<=sqrt(x);i++)
    {
        if(x%i==0)
        { 
        flag=0;
        break;
        }
    }
    return flag;
}



int main()
{
    int a,b;
    while(scanf("%d %d",&a,&b)!=EOF)
    {   int sum=0;
        if(a>b)

        {
            int temp=a;
            a=b;
            b=temp;
        }
        if(b-a==1)
        {
            sum=0;
            printf("%d\n",sum);
            continue;
        }
        for(int i=a+1;i<b;i++)
        {   
            if(check_prime(i)==1) sum+=i;
        }
    printf("%d\n",sum);
    }
}