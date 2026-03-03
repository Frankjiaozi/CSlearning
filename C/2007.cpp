#include <stdio.h>
//数字转数组
void transfer(int x,int arr[])//9876
{
int i=3;
while(i>=0)
    {   
      arr[i]=x%10;
      x=x/10;
      i--;
    }
}

//交换
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
//加密
void encrypt(int arr[])
{
    for(int i=0;i<4;i++)
    {
        arr[i]=(arr[i]+5)%10;
    }
    swap(&arr[0],&arr[3]);
    swap(&arr[1],&arr[2]);
}
int main()
{   int x;
    scanf("%d",&x);
    int arr[4];
    transfer(x,arr);
    encrypt(arr);
    for(int i=0;i<4;i++)
    {
        printf("%d",arr[i]);
    }

}