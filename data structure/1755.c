#include <stdio.h>  


void sort(int arr[],int count)
{
    for(int i=0;i<count-1;i++)
    {
        for(int j=0;j<count-1-i;j++)
        {
            if(arr[j]<0&&arr[j+1]>0)
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
int main()
{
    int arr[10000];
    int count=0;
    while(1)
    {
        int temp;
        scanf("%d",&temp);
        if(temp==0) break;
        arr[count]=temp;
        count++;
    }
    sort(arr,count);
    for(int i=0;i<count;i++)
    {
        printf("%d ",arr[i]);
    }
}