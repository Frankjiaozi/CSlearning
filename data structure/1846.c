#include <stdio.h>
#include <string.h>
int main()
{
    int x;
    scanf("%d",&x);//80
    if(x==0)
    {
        printf("1 0");
        return 0;
    }
    int rest = x;
    int val=0;
    int count=0;
    int arr[100];
    while(rest>0)
    {
        val = rest%8;
        arr[count] = val;
        rest = rest/8;
        count++;
    }

printf("%d ",count);
for(int i=0;i<count;i++)
{
    printf("%d",arr[i]);
}
}