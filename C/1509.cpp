#include <stdio.h>
void sort(float arr[],int n)
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






#define max(arr) \
do \
{\
        sort(arr,3);                    \
        printf("%.3f\n",arr[0]);\
}while(0);\


int main()
{
    float arr[3];
    for(int i=0;i<3;i++)
    {
        scanf("%f",&arr[i]);
    }


    max(arr);
    max(arr);
}