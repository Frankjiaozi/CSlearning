#include <stdio.h>
int main()
{   
    int a,b,a1,b1;
    
    while(scanf("%d %d %d %d",&a,&b,&a1,&b1)!=EOF)
{
    int c,d,c1,d1;
    scanf("%d %d %d %d",&c,&d,&c1,&d1);//(a,b)  (a1,b1)  (c,d)  (c1,d1)
    int k1 = (float)a - (float)a1 / (float)b - (float)b1;
    int k2 = (float)c - (float)c1 / (float)d - (float)d1;
    if((a-a1==0&&c-c1==0)||(b-b1==0&&d-d1==0))
    {
        printf("Yes");
        
    }
    
}
}