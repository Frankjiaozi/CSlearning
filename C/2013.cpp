#include <stdio.h>
int main()
{   int flag=1;
    int n;
    scanf("%d",&n);
    int arr[n];
    //输入数组
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    //建立下标
    int low=0;
    int high=1;
    while(arr[high-1]!=arr[high])//2  3 1 1 1 2
    {
        high+=1;
        if(high>n)
        {
            flag=0;
            break;
        }
    }
    //如果找到相等，循环Break，low变成high
    low=high-1;
    //现在从第一个重复的开始找
    while(arr[low]==arr[high])
    {
        high++;
    }
    int result1=low;
    int result2=high-1;
    if(flag==1) printf("The longest equal number list is from %d to %d.",result1,result2);
    else if(flag==0) printf("No equal number list.");


    

}