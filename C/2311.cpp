#include <stdio.h>
int  Input(int arr[])
{   int temp;
    int count=0;
    while(scanf("%d",&temp)!=EOF && temp != 0)
    {
        arr[count] = temp;
        count++;
    }
    return count;
}
int MAX(int arr[],int count)
{   int max=arr[0];
    for(int i=0;i<count;i++)
    {
        if(arr[i]>max) max=arr[i];
    }
    return max;
}


int MIN(int arr[],int count)
{   int min=arr[0];
    for(int i=0;i<count;i++)
    {
        if(arr[i]<min) min=arr[i];
    }
    return min;
}


float SUM(int arr[],int count)
{   float sum=0;
    for(int i=0;i<count;i++)
    {
        sum+=arr[i];
    }
    return sum;
}


void statistics(int count, int arr[], int *max, int *min, float *avg)
{
*min=MIN(arr,count);
*max=MAX(arr,count);
float sum=SUM(arr,count);
*avg=sum/count;


}


int main()
{   int max=0; int min=0; float avg=0.0;
    int arr[100];
    int count = Input(arr);
    statistics(count,arr,&max,&min,&avg);
    printf("Num=%d\n",count);
    printf("Max=%d\n",max);printf("Min=%d\n",min);printf("Avg=%.3f\n",avg);




}

  