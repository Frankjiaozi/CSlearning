#include <stdio.h>
#include <string.h>

typedef struct Music
{
    char name[100];
    int time;
    int score;
}Music;

int point(int total_time,int play_time)
{
if(play_time>=0 && play_time<(float)total_time/5.0)
{
    return 0;
}
else if(play_time>=(float)total_time/5.0 && play_time<(float)total_time*2.0/5.0)
{
    return 1;
}
else if(play_time>=(float)total_time*2.0/5.0 && play_time<(float)total_time*3.0/5.0)
{
    return 2;
}
else if(play_time>=(float)total_time*3.0/5.0 && play_time<(float)total_time*4.0/5.0)
{
    return 3;
}
else if(play_time>=(float)total_time*4.0/5.0 && play_time<total_time)
{
    return 4;
}
else if(play_time==total_time)
{
    return 5;
}
return  -1;
}

void sort_score(Music music_list[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(music_list[j].score<music_list[j+1].score)
            {

                
                Music temp=music_list[j];
                music_list[j]=music_list[j+1];
                music_list[j+1]=temp;
            }
            else if(music_list[j].score==music_list[j+1].score)
            {
                if(strcmp(music_list[j].name,music_list[j+1].name)>0)
                {
                    Music temp=music_list[j];
                    music_list[j]=music_list[j+1];
                    music_list[j+1]=temp;
                }
            }
        }
    }
    
}

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF&& n!=0)
    {
    //定义结构体数组
    Music music_list[n];
    for(int i=0;i<n;i++)
    {   int m,s;
        scanf("%s",music_list[i].name);
        scanf("%d:%d",&m,&s);
        music_list[i].time=m*60+s;
    }
//
    for(int i=0;i<n;i++)
    {
        music_list[i].score=0;
    }

    //听歌记录
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {   
        char str[100];
        scanf("%s",str);
        int m,s;
        int time;
        scanf("%d:%d",&m,&s);
        time=m*60+s;
        for(int j=0;j<n;j++)
        {
            if(strcmp(str,music_list[j].name)==0)
            {
                music_list[j].score+=point(music_list[j].time,time);
            }
        } 
    }
    sort_score(music_list,n);
    for(int i=0;i<n;i++)
    {
        printf("%s %d\n",music_list[i].name,music_list[i].score);
    }
}
    
}