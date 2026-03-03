#include <stdio.h>
#include <string.h>
typedef struct
{
    char country[20];
    int gold;
    int silver;
    int bronze;
}MEDAL;

MEDAL medal[500];



int find(char country[],int n)
{
    for(int i=0;i<n;i++)
    {
        if(strcmp(medal[i].country,country)==0)
        {
            return i;
        }
    }
    return -1;
}
int main()
{   
    int n;
    scanf("%d",&n);//第一行一个整数N，代表奖牌的数量

    //开始输入数据
    int count=0;
    for(int i=0;i<n;i++)
    {
        char contry[10];
        char medal_temp[10];
        scanf("%s %s",contry,medal_temp);
        if(find(contry,count)==-1)
        {
            strcpy(medal[count].country,contry);
            
            
                    if(strcmp(medal_temp,"jin")==0)
                    {
                        medal[count].gold++;
                    }
                    else if(strcmp(medal_temp,"yin")==0)
                    {
                        medal[count].silver++;
                    }
                    else if(strcmp(medal_temp,"tong")==0)
                    {
                        medal[count].bronze++;
                    }
                    count++;
        }
        else if(find(contry,count)!=-1)
        {   
            for(int j=0;j<n;j++)
            {
                if(strcmp(medal[j].country,contry)==0)
                {
                    if(strcmp(medal_temp,"jin")==0)
                    {
                        medal[j].gold++;
                        break;
                    }
                    else if(strcmp(medal_temp,"yin")==0)
                    {
                        medal[j].silver++;
                        break;
                    }
                    else if(strcmp(medal_temp,"tong")==0)
                    {
                        medal[j].bronze++;
                        break;
                    }
                }
            }
        }
        
    }




    //开始排序
    for(int  i=0;i<count-1;i++)
    {
        for(int j=0;j<count-i-1;j++)
        {
            int need_swap=0;

            if(medal[j].gold<medal[j+1].gold)
            {
                need_swap=1;
            }
            else if(medal[j].gold == medal[j+1].gold)
            {
                if(medal[j].silver<medal[j+1].silver)
                {
                    need_swap=1;
                }
                else if(medal[j].silver == medal[j+1].silver)
                {
                    if(medal[j].bronze<medal[j+1].bronze)
                    {
                        need_swap=1;
                    }
                }
            }
            if(need_swap==1)
            {
                MEDAL temp  = medal[j];
                medal[j]=medal[j+1];
                medal[j+1]=temp;
            }

        } 
       
        
    }

    //输出排序结果
    for(int i=0;i<count;i++)
    {
        printf("%s %d %d %d\n",medal[i].country,medal[i].gold,medal[i].silver,medal[i].bronze);
    }

}