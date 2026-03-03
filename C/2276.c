#include <stdio.h>

void sort(int arr[])
{
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10-i;j++)
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



int main()
{   
    int arr1[11];
    int arr2[11];

    while(scanf("%d",&arr1[0])!=EOF)
    {   int count=0;
        for(int i=1;i<11;i++)
        {
            scanf("%d",&arr1[i]);
        }
        for(int i=0;i<11;i++)
        {
            scanf("%d",&arr2[i]);
        }
        //½øĞĞÅÅĞò
        sort(arr1);
        sort(arr2);
        for(int i=0;i<11;i++)
        {
            for(int j=0;j<11;j++)
            {
                if(arr1[i]>arr2[j] && arr1[i]!=0 && arr2[j]!=0) 
                {
                    arr1[i]=0;
                    arr2[j]=0;
                    count++;
                }
            }
        }
        
        printf("%d\n",count);




    }
}