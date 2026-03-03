#include <stdio.h>
//计算约数个数
int cal(int x)
{   int count=0;
    for(int i=1;i<=x;i++)
    {
        if(x%i==0) count++;
    }
    return count;
}
//冒泡排序
void bubble_sort(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(arr[j]<arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

typedef struct number
{
    int index;
    int value;
}number;





int main ()
{   
    int n;
    while(scanf("%d",&n)!=EOF)
    {   number arr[n];
        int arr_st[n];
        for(int i=0;i<n;i++)
        {
            scanf("%d",&arr[i].value);
            arr_st[i]=arr[i].value;
        }
        //初始化结构体
        for(int i=0;i<n;i++)
        {
            arr[i].index=i;
        }
    for(int i=0;i<n;i++)
    {
        arr[i].value=cal(arr[i].value);
    }


    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(arr[j].value<arr[j+1].value)
            {
                number temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
int result=arr[0].index;
    printf("%d\n",arr_st[result]);
    }
}