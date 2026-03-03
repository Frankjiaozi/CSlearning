#include <stdio.h>

typedef struct
{
    char num[20];
    char name[20];
    int score1;
    int score2;
    int score3;
}STU;
//定义结构体数组
STU stu[100];

void input(int n,STU a[])
{
    for(int i=0;i<n;i++)
    {
        scanf("%s %s %d %d %d",a[i].num,a[i].name,&a[i].score1,&a[i].score2,&a[i].score3);
    }
}

void print(int n,STU a[])
{
    for(int i=0;i<n;i++)
    {
        printf("%s,%s,%d,%d,%d\n",a[i].num,a[i].name,a[i].score1,a[i].score2,a[i].score3);
    }
}


int main()
{
int n;
scanf("%d",&n);
input(n,stu);
print(n,stu);
return 0;
}