#include <stdio.h>
int main()
{   int b;
    scanf("%d",&b);
    int x=0;;
    int a[11]={1,4,6,9,13,16,19,28,40,100,0};
    while(a[x]<b)
    {
        x=x+1;
    }
for(int i=10;i>=x;i--)
{
a[i]=a[i-1];
}
a[x]=b;
for(int i=0;i<11;i++)
{
    printf("%d\n",a[i]);
}
}