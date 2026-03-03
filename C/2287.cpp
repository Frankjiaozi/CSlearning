#include <stdio.h>
int cal(int x)
{  if(x==1)
    {
        return 1;
    }
    int result;
    result=cal(x-1)*2+1;
    return result;
}





int main()
{   int n;
    while(scanf("%d",&n)!=EOF&&n!=0)
    {
        printf("%d\n",cal(n));
    }
}