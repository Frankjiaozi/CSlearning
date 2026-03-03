#include <stdio.h>
int runnian(int n)
{
    if(n%4==0&&n%100!=0) return 1;
    else if(n%400==0) return 1;
    else return 0;
}
int main()
{
    int n=0,y=0,r=0;
    int x=0;
    int month0[]={31,28,31,30,31,30,31,31,30,31,30,31};
    int month1[]={31,29,31,30,31,30,31,31,30,31,30,31};
    while(scanf("%d %d %d",&n,&y,&r)!=EOF)
    {
        if(y==1) 
        {
            x=x+r;
            printf("%d\n",x);
            x=0;
        }
        else if(y!=1)
        {
            
            
            if(runnian(n)==1)
            {
                int i;
                for(i=0;i<y-1;i++)
                {
                    x=x+month1[i];
                }
                x=x+r;
            }
            else if(runnian(n)==0)
            {
                int i;
                for(i=0;i<y-1;i++)
                {
                    x=x+month0[i];
                }
                x=x+r;
            }
            printf("%d\n",x);
            x=0;
        }
    }
    return 0;
}