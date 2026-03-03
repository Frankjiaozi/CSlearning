#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//数值交换函数      
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

//升序排列
void bubblesort_up(int arr[],int n)
{
for(int i=0;i<n-1;i++)
{
    for(int j=0;j<n-1-i;j++)
    {
        if(arr[j]>arr[j+1])
        {
            swap(&arr[j],&arr[j+1]);
        }
    }
}
}
//降序排列
void bubblesort_down(int arr[],int n)
{
for(int i=0;i<n-1;i++)
{
    for(int j=0;j<n-1-i;j++)
    {
        if(arr[j]<arr[j+1])
        {
            swap(&arr[j],&arr[j+1]);
        }
    }
}
}

//实现数组转数字
int sum(int arr[],int n)//9876
{
    int result=0;
    for(int i=0;i<n;i++)
    {
        result+=arr[i]*pow(10,3-i);

    }
    return result;
}
//实现数字转数组
void transfer(int arr[],int x)//9876
{   int i=3;
    while(i>=0)
    {   
        arr[i]=x%10;
        x=x/10;
        i--;
    }
}
//操作函数
int finals(int x)
{
int arr_up[4];
int arr_down[4];
transfer(arr_up,x);
transfer(arr_down,x);
bubblesort_up(arr_up,4);
bubblesort_down(arr_down,4);
int bigger=sum(arr_down,4);
int smaller=sum(arr_up,4);
return bigger-smaller;

}
int main()
{
    int m;

scanf("%d",&m);
printf("%d",m);
int temp=-1;
for(int i=0;i<1000;i++)
{   temp=m;
    m=finals(m);
    printf("->%d",m);
    if(m==temp) break;

}

}