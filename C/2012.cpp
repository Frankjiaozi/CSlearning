    #include <stdio.h>
    #include <string.h>
int is_other_char1(char c) {
    if ((c >= '0' && c <= '9') ||  // 数字
        (c >= 'A' && c <= 'Z') ||  // 大写字母  
        (c >= 'a' && c <= 'z')) {  // 小写字母
        return 0;  // 不是其他字符
    } else {
        return 1;  // 是其他字符
    }
}



int safe(char str[])
{
int count=0;
//记录0-9
for(int i=0;i<(int)strlen(str);i++)
{
if(str[i]>='0'&&str[i]<='9')
{
    count+=1;
    break;
}
}
//记录字母
for(int i=0;i<(int)strlen(str);i++)
{
if((str[i]>='a'&&str[i]<='z'))
{
    count+=1;
    break;
}
}

for(int i=0;i<(int)strlen(str);i++)
{
if((str[i]>='A'&&str[i]<='Z'))
{
    count+=1;

    break;
}
}
//记录其他字符
for(int i=0;i<(int)strlen(str);i++)
{
if(is_other_char1(str[i])==1)
{
    count+=1;
    break;
}
}
return count;
}


int main()
{   int n;
    int flag=0;
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;i++)
    {char str[20];
        scanf("%s",str);
    if((int)strlen(str)<6) flag=1;
    else
    {
        if(safe(str)==1) flag=1;
        else if(safe(str)==2) flag=2;
        else if(safe(str)>=3) flag=3;
    }
    if(flag==1) printf("Not Safe\n");
    else if(flag==2) printf("Medium Safe\n");
    else printf("Safe\n");
    }

}