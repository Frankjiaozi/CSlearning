#include <stdio.h>
int main()
{int l=0,m=0;
int arr[10000]={0};
scanf("%d %d",&l,&m);
{
for(int i=0;i<=l;i++)
{
arr[i]=1;
}
for(int i=1;i<=m;i++)
{
int x=0,y=0;
scanf("%d %d",&x,&y);
for(int i=x;i<=y;i++)
{
    arr[i]=0;
}
}
//ÇóºÍ
int sum=0;
for(int i=0;i<=l;i++)
{
sum=sum+arr[i];
}
printf("%d",sum);
}
}