#include <stdio.h>
int index1,index2;
    //横向找最大
    int find_max(int arr[],int n)
    {   int max=arr[0];
        int index=0;
        for(int j=0;j<n;j++)
        {
            if(arr[j]>max) 
            {
                max=arr[j];//1 2 3
                           //4 6 7
                index=j;
            }
        }
        return index;
    }
int main()
{   
    int n;
    scanf("%d",&n);
    int arr[n][n];
    int temp;
    //输入
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&temp);
            arr[i][j]=temp;
            //printf("%d",arr[i][j]);
        }
    }
    //处理
for(int i=0;i<n;i++)
{
    for(int j=find_max(arr[i],n);j<n;j++)
    {   int min=0;
        for(int t=0;t<n;t++)
        {
            if(arr[t][j]<min)

            {  
                index1=t;
                index2=j;              
            }
        }
    }
}

printf("%d %d",index1,index2);
}