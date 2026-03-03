#include <stdio.h>
int* transfer(int arr[],int n)
{   
    int temp1[n];
    int temp2[n];
    int a=0;
    for(int i=0;i<n;i++)
    {
        temp1[a]=arr[i];
        a++;
    }
    int b=0;
    for(int i=n;i<2*n;i++)
    {
        temp2[b]=arr[i];
        b++;
    }
//写入
b=0;
for(int i=0;i<2*n;i=i+2)
{
arr[i]=temp2[b];
b++;
}
a=0;
for(int i=1;i<2*n;i=i+2)
{
arr[i]=temp1[a];
a++;
}
return arr;
}

int judge(int arr1[],int arr2[],int n)//1是一样，0是不一样
{int flag=1;
for(int i=0;i<2*n;i++)
{
    if(arr1[i]!=arr2[i])
    {
        flag=0;
    }
}
return flag;
}

//复制数组
void copy(int init_arr[],int arr[],int n)
{
    for(int i=0;i<2*n;i++)
    {
        init_arr[i]=arr[i];
    }
}








int main()
{   
    int n;
    scanf("%d",&n);
    int arr[2*n];
    for(int i=0;i<2*n;i++)
    {
        arr[i]=i+1;
    }

//开始操作
int m=0;
int init_arr[2*n];
copy(init_arr,arr,n);
transfer(arr,n);
while(judge(arr,init_arr,n)!=1)
{   
   
    transfer(arr,n);
    m++;
}
m=m+1;
printf("经%d次洗牌回到初始状态",m);

}