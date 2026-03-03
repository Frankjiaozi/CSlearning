#include <stdio.h>
#include <string.h>






int judge(char x)
{   
    int flag=1;
    if((x>='a'&&x<='z')||(x>='A'&&x<='Z')||(x>='0'&&x<='9'))    flag=0;
return flag;
}



int count(char str[],int len)//num表示最终有几个数组，num-1表示分隔符的数量
{   int result=0;
    for(int i=0;i<len;i++)
    {
        if(judge(str[i])==1) result++;
    }
    return result+1;
}

int main()
{   



    char str[100];
    scanf("%s",str);
    int len=(int)strlen(str);
    int num=count(str,len);
    for(int i=0;i<len;i++)
    {
        if(judge(str[i])==1) str[i]='\0';
    }
char *p=str;
int k=0;
while(*p!='\0')//apple\0banana\0orange\0grape\0
{   
    printf("%s\n",p);
    k++;
    if(k==num) break;
    while(*p!='\0')
    {
        p++;
    }
    p++;
}

}