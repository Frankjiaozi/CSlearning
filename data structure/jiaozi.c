#include <stdio.h>
int main()
{
    int arr[1000];
    int count = 0;
    while(scanf("%d",&arr[count])!=EOF)
    {
        count++;
    }
    for(int i=0;i<count;i++)
    {
        printf("%d ",arr[i]);
    }
   }
