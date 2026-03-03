#include <stdio.h>
int main()
{   
    int T;
    scanf("%d",&T);
    for(int j=0;j<T;j++)
    {
        int m,n;
        scanf("%d %d",&n,&m);
        int d1,d2;
        for(int i=0;i<m;i++)
        {
            scanf("%d %d",&d1,&d2);
            n--;
        }
        printf("%d\n",n);
    }
}