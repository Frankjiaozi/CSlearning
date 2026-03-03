#include <stdio.h>
int main()
{   int f[41];
    f[2]=1;f[3]=2;
    int m;
    for(int i=4;i<=40;i++)
    {
        f[i]=f[i-1]+f[i-2];
    }
    while(scanf("%d",&m)!=EOF)
    {
        printf("%d\n",f[m]);    
    }
}