#include <stdio.h>
#include <string.h>
///////////////////
//char result[1000];

///
void bubble_sort(int arr[],int length)
{   
    for(int i=0;i<length-1;i++)//3,1,5,3,
    {
        for(int j=0;j<length-1-i;j++)
        {
            if(arr[j+1]<arr[j])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
int  sort(int arr[],int m)
{
int flag=0;
  for(int a=0;a<=5;a++)
    {
        for(int b=0;b<=5-a;b++)
        {
            for(int c=0;c<=5-a-b;c++)
            {
                for(int d=0;d<=5-a- b-c;d++)
                {
                        if(arr[0]*a+arr[1]*b+arr[2]*c+arr[3]*d==m)
                        {
                            return m;
                        }
                }
                }
            }
        }
return flag;
}
int main()
{   
    //输入四种邮票的面额
    int arr[4];
    for(int i=0;i<4;i++)
    {
        int a;
        scanf("%d",&a);

        arr[i]=a;
    }
    //数组长度
    int length=(int)(sizeof(arr)/sizeof(int));
    //小到大排序
    bubble_sort(arr,length);
    for(int m=1;m<=500;m++)
    {
        if(sort(arr,m)==0) 
        {
            printf("%d",m-1);
            break;
        }
    }
    
}

