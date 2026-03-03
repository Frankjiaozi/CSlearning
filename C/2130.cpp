    #include <stdio.h>
    #include <math.h>
    int main()
    {double a,b,c;
        while(scanf("%lf %lf %lf",&a,&b,&c)!=EOF)
        {
            double derta = b*b - 4*a*c;
            if(derta<0)
            {
                printf("NO\n");
            }
            else if(derta>=0)
            {
                double x1=(-b+sqrt(derta))/(2*a);
                double x2=(-b-sqrt(derta))/(2*a);
                if(x1<x2)
                {
                    printf("%.2lf %.2lf\n",x2,x1);
                }
                else if(x1>x2)
                {
                    printf("%.2lf %.2lf\n",x1,x2);
                }
                else if(x1==x2)
                {
                    printf("%.2lf %.2lf\n",x1,x2);
                }
            }
        }
    }