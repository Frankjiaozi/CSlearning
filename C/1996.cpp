#include <stdio.h>
//输出每个数字的因数之和sum
int sum_fac(int a)
{int sum=0;
for(int i=1;i<a;i++)
{
if(a%i==0) sum=sum+i;
}
return sum;
}

int main()
{
int m,n;
scanf("%d %d",&m,&n);
//int b_a[n-m]={0};
//int final[n-m]={0};
for(int j=m;j<=n;j++)//从m到n循环数字j
{int temp0=0;
    temp0=sum_fac(j);
if((temp0>=m)&&temp0<=n&&sum_fac(temp0)==j&&j<temp0) 
printf("%d %d\n",j,temp0);
}
}
