#include <stdio.h>
int main()
{
    int len1,len2;
    scanf("%d %d",&len1,&len2);
    int arr1[len1];
    int arr2[len2];
    for(int i=0;i<len1;i++)
    {
        scanf("%d",&arr1[i]);
    }
    for(int i=0;i<len2;i++)
    {
        scanf("%d",&arr2[i]);
    }
int sum=0;
int result[len1];
    //开始比较
    for(int i=0;i<len1;i++)
    {   int count=0;
        for(int j=0;j<len2;j++)
        {
            if(arr1[i]>arr2[j])
            {
                count++;
            }
        }
        result[i]=count;
        sum+=count;
    }
    printf("%d",sum);
}