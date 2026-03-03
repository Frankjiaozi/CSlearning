#include <stdio.h>
void sort(int arr[],int n)
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



//统计出现次数
int cal(int x,int arr[],int len)
{   int count=0;
    for(int i=0;i<len;i++)
    {
        if(x==arr[i]) count++;
    }
    return count;
}




int main()
{   int arr[10];
    for(int i=0;i<10;i++)
{
    scanf("%d",&arr[i]);
}

//排序
sort(arr,10);
//
int max_count=1;
int index=0;
int current_count=1;
    for(int i=1;i<10;i++)
    {
        if(arr[i-1]==arr[i])  current_count++;
        else current_count=1;
    
        if(current_count > max_count) 
        {
            max_count=current_count;
            index=i;
        }

    }
            printf("%d\n",arr[index]);
            printf("%d",max_count);
}

