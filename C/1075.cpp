#include <stdio.h>
#include <math.h>
int main()
{
    int m,n;
    scanf("%d %d",&m,&n);
    int final[m];
    int f[m];
    int g[n];
    for(int i=0;i<m;i++)
    {int a=0;
    scanf("%d",&a);
    f[i]=a;
    }
    for(int i=0;i<n;i++)
    {int b=0;
    scanf("%d",&b);
    g[i]=b;
    }

    for(int i=0;i<m;i++)
    {final[i]=abs(f[i]-g[0]);
        for(int j=0;j<n;j++)
        {
        if((abs(f[i]-g[j]))<final[i]) 
        {final[i]=abs(f[i]-g[j]);
        } 
        }
        }
int final_min=final[0];
for(int i=0;i<m;i++)
{

if(final[i]<final_min) final_min=final[i];
}
printf("%d",final_min);
return 0;
}
