#include <stdio.h>
int main()
{   
    int n,m;
    int count=0;
    scanf("%d %d",&m,&n);
    int arr1[m];
    int arr2[n];
    //输入两个数组
    for(int i=0;i<m;i++)
    {
        scanf("%d",&arr1[i]);//1，2，2，3，3
    }

    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr2[i]);//1，2，2，2，3
    }
    int k=(m<n)?m:n;
    //建立指针
    int *p1=arr1;
    int *p2=arr2;
    while(p1<arr1+m && p2<arr2+n)
    {
        if(*p1==*p2) 
        {
            count++;
            p1++;
            p2++;
        }
        
        else if(*p1<*p2) p1++;

        else p2++;
    }
    
printf("%d",count);

}