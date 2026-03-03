#include <stdio.h>
#include <math.h>
int huiwen(int a)
{
//计算数字位数
int temp=a;
int count=0;
while(temp>0)
{
temp=temp/10;
count++;
}
int arr[count];
if(a>=10&&a<=99)
{
    for(int i=0;i<2;i++)
    {
    arr[0]=a/10;
    arr[1]=a-arr[0]*10;
    }
}
else if(a>=100&&a<=999)
{
    for(int i=0;i<3;i++)
    {
    arr[0]=a/100;//999
    arr[1]=(a-arr[0]*100)/10;
    arr[2]=a-(arr[0]*100+arr[1]*10);
    }
}
else if(a>=1000&&a<=9999)//7788
{
    for(int i=0;i<4;i++)
    {
    arr[0]=a/1000;
    arr[1]=(a-arr[0]*1000)/100;
    arr[2]=(a-(arr[0]*1000+arr[1]*100))/10;
    arr[3]=a%10;
    }
}
else if(a==10000) 
{
arr[0]=1;
arr[1]=0;
arr[2]=0;
arr[3]=0;
arr[4]=0;
}
int temp1=0;
for(int i=0;i<((count+1)/2);i++)
{
if(arr[i]==arr[count-i-1])  temp1+=1;
}
if (temp1==(count+1)/2) return 1;
else return 0;
}



int sushu(int a)
{int flag=1;
for(int i=2;i<a;i++)
{
if(a%i==0) flag=0;
}
if(flag==1) return 1;
else return 0;
}



int main()
{
int a,b;
scanf("%d %d",&a,&b);
int c=0;

for(int i=a;i<=b;i++)
{
if(sushu(i)==1&&huiwen(i)==1)
{
    if(i>=10&&i<=99) {printf("    %d",i);c+=1;}
    if(i>=100) {printf("   %d",i);c+=1;}
    if(c%5==0) printf("\n");

}
}

}