#include <stdio.h>
int sum(int arr[],int x)
{   int result=0;
    for(int i=x;i<62;i++)
    {
        result+=arr[i];
    }
return result;
}
int main()
{
    int arr[62];
    for(int i=0;i<62;i++)//1代表停电，0代表不停电
    {
        arr[i]=0;
    }
int n=0;
int add=2;
while(n<62)
{
    //printf("%d ",n);
arr[n]=1; 
n=n+add;
add++;
}
//处理输入
int m,d;
while(scanf("%d/%d",&m,&d)!=EOF&&m!=0&&n!=0)
{   int index=0;
if(m==7)
{
    index=d-1;
}
else if(m==8)
{
    index=31+d-1;
}
printf("%d\n",sum(arr,index));
}

}
