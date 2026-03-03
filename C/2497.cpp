#include <stdio.h>
//n次方函数
float product(float x,int n)
{   float result=1;
    for(int i=0;i<n;i++)
    {
        result=result*x;
    }
    return result;
}
//计算p
float cal_p(float p,int n, float r)
{
    float pmt=p*r*product(1+r,n)/(product(1+r,n)-1);
    return pmt;
}



int main()
{
    float p;int n; float  pmt;
    scanf("%f %d %f",&p,&n,&pmt);
    float low=0.0;
    float high=1.0;
    float mid=0;
    for(int i=0;i<100;i++)
    {
         mid=(high+low)/2.0;
        if(cal_p(p,n,mid)>pmt)  high=mid;
        else if(cal_p(p,n,mid)<pmt) low=mid;
    }
    printf("%.3f%%",100*mid);

    

}