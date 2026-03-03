#include <stdio.h>

typedef struct STU
{
    int index;
    int point;


}STU;


int main()
{
    STU people[10];
//初始化结构体
for(int i=0;i<10;i++)
{
    people[i].index=i;
}
//处理输入
for(int i=0;i<10;i++)
{
    scanf("%d",&people[i].point);
}
//排序
for(int i=0;i<9;i++)
{
    for(int j=0;j<9-i;j++)//2 3 5 1
    {
        if(people[j].point < people[j+1].point)
        {
            STU temp=people[j];
            people[j]=people[j+1];
            people[j+1]=temp;
        }
    }
}
//输出
int k=0;
while(people[k].point == people[0].point)
{
    printf("%d\n",people[k].index);
    k++;
}



}