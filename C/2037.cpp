#include <stdio.h>
#include <string.h>
#define MAX 30//该系统所能容纳的最大数量
int count=0;

typedef struct people
{
    char name[20];
    char sex[7];
    typedef struct  Birthday
    {
        int year;
        int month;
        int day;
    }Birthday;

    Birthday birthday;
    
}people;


people arr_people[MAX];//实例化结构体数组

////////////////////////////////////////////////////////////
                //函数区//

void print_struct(int i)
{
    printf("%s %s %d-%d-%d\n",arr_people[i].name,arr_people[i].sex,arr_people[i].birthday.year,arr_people[i].birthday.month,arr_people[i].birthday.day);
}




void find_name(char need_find[])
{   int flag=0;
    for(int i=1;i<=count;i++)
    {
        if(strcmp(need_find,arr_people[i].name)==0)
        {
            print_struct(i);
            flag=1;
        }
    }
    if(flag==0) printf("No such name\n");
}








/////////////////////////////////////////////////////////////




int main()
{   char command[100];
    while(1)
    {
        scanf("%s",command);
        //退出逻辑
        if(strcmp(command,"quit")==0)
        {
            break;
        }
        //添加操作
        if(strcmp(command,"add")==0)
        {   count++;
            
            scanf("%s",arr_people[count].name);
            scanf("%s",arr_people[count].sex);
            scanf("%d",&arr_people[count].birthday.year);
            scanf("%d",&arr_people[count].birthday.month);
            scanf("%d",&arr_people[count].birthday.day);
        }

        //查询
        if(strcmp(command,"name")==0)
        {
            char need_find[100];
            scanf("%s",need_find);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
            char need_find[100];
            scanf("%s",need_find);
            int flag=0;
            for(int i=1;i<=count;i++)
            {
                if(strcmp(need_find,arr_people[i].sex)==0)
                {
                    print_struct(i);
                    flag=1;
                }
            }
            if(flag==0) printf("No such sex\n");
        }
    }
}