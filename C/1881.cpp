#include <stdio.h>
int main()
{
//建立数组
int arr[10]={0};
for(int i=0;i<10;i++)
{int a=0;
scanf("%d",&a);
arr[i]=a;}
//计算最大和最小
int max=arr[0],min=arr[0];
for(int i=0;i<10;i++)
{
if(arr[i]>max)  max=arr[i];
if(arr[i]<min) min=arr[i];
}
//计算总额
int sum=0;
for(int i=0;i<10;i++)
{
sum=arr[i]+sum;
}
//计算平均值
float avr=0.0;
avr=(sum-min-max)/8.0;
printf("%.3f",avr);
return 0;
}