#include <stdio.h>
void sort(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1]&&arr[j+1]<0)
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}




int main()
{   int n;
   
    while(scanf("%d",&n)!=EOF)
    {    int arr[n];
        for(int i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }

sort(arr,n);

        //Êä³ö
        for(int i=0;i<n;i++)
        {
            printf("%d ",arr[i]);
            if(i==n-1) printf("\n");
 
        }
        

    }
}