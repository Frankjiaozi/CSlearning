#include <stdio.h>
void sort(float arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                float temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

float sum(float arr[],int n)
{
    float s=0;
    for(int i=0;i<n;i++)
    {
        s+=arr[i];
    }
    return s;
}
int main()
{
    float arr[7];
    while(1)
    {int flag=0;
    char name[100];
    for(int i=0;i<7;i++)
    {
        if(scanf("%f",&arr[i])!=1)
        {
            
            flag=1;
            break;
        }
    }
    if(flag==1)
    {
        break;
    }
    scanf("%s",name);
    sort(arr,7);
    arr[0]=0.0;
    arr[6]=0.0;
    float s=sum(arr,7);
    float result=(float)s/5.0;
    printf("%s %.2f\n",name,result);
    }

}