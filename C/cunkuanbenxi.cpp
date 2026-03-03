#include <stdio.h>
int main()
{
    double m=0,r=0;
    int y;
    while(scanf("%lf %d %lf",&m,&y,&r)!=EOF)
        {
        for (int i=0;i<y;i++)
            {m=m+m*r;}
        printf("%.2f\n",m);
        }
    return 0; 
}