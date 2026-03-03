#include <stdio.h>
int x1=0,x2=0,x3=0;
int scf(int a=0,int b=0)
{
int result0=1;
for(int i=0;i<b;i++)
{
    result0=result0*a;
}
return result0;

}
void qz(int c,int *x1,int *x2,int *x3)
{
*x1=(c/100)%10;
*x2=(c/10)%10;
*x3=c%10;
}
int main()
{int n=0;
while(scanf("%d",&n)!=EOF)
{
int result=0;
result=scf(n,3);
qz(result,&x1,&x2,&x3);
printf("%d%d%d\n",x1,x2,x3);

}
}
