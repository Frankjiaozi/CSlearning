#include <stdio.h>
int main()
{int a,b;
while(1)
{  
     double total_value=0.0;
   int m,rest_time;
    scanf("%d %d",&m,&rest_time);
    
    struct exam_paper//定义结构体
    {
        int needtime;
        int value;
        double avrvalue;
    };

    struct  exam_paper test[m];//名为test的数组，储存了m个exam_paper结构体
//结构体输入
for(int i=0;i<m+1;i++)
{   
    scanf("%d %d",&a,&b);
test[i].needtime=a;
test[i].value=b;
test[i].avrvalue=(double)b/(double)a;
if(a==0&&b==0) break;
}
//根据avrvalue冒泡排序
for(int i=0;i<m-1;i++)
{
    for(int j=0;j<m-1-i;j++)//9,0,2,3,
    {
        if(test[j].avrvalue<test[j+1].avrvalue)
        {
            struct exam_paper  temp=test[j+1];
            test[j+1]=test[j];
            test[j]=temp;
        }
    }
}
//有resttime的时间，resttime-=每张试卷需要的时间，然后
int temp1;

    for(int i=0;i<m;i++)
    {   if(rest_time<0) break;
        rest_time-=test[i].needtime;
        total_value+=test[i].value;
        temp1=i;
    }
if(rest_time<0)
{
    total_value+=(double)rest_time/(double)test[temp1].needtime*test[temp1].value;
}
    

printf("%.2lf",total_value);
}
}
