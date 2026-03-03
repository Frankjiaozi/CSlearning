#include <stdio.h>
int main()
{
int x=1;
int y=2;
int n=0;
int c=0;
while (scanf("%d",&n)!=EOF)
{
if(n==1) printf("%d\n",x);
    else if (n==2) printf("%d\n",y);
    else if(n==0) break;
    else 
        {int i;
        int a=1;
        int b=2;
        for(i=3;i<n+1;i++)
            {c=a+b;
            a=b;
            b=c;}
        printf("%d\n",c);}
}
return 0;
}



