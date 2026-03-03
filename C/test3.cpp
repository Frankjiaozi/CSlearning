#include <stdio.h>
#include <math.h>
int max( float a,float b,float c)
{       
    if(a>=b&&a>=c)
        c=a;
    else if(b>=a&&b>=c)
        c=b;
    else 
        c=c;
    return c;
}
int main()
{
    float a=0,b=0,c=0,s=0,area=0,perimeter=0,t=0;
    while(scanf("%f%f%f",&a,&b,&c)!=EOF)
    {  
       perimeter=a+b+c;
        s=(a+b+c)/2;
       t=max(a,b,c);
       if((perimeter-t)>t)
       {
        area=sqrt(s*(s-a)*(s-b)*(s-c));
        printf("%.2f\n%.2f\n",area,perimeter);
       
       }
       else
            {
                printf("There sides do not correspond to a valid triangle¡±¡£");
            }
    }
     return 0;
}

