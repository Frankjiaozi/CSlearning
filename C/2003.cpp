#include <stdio.h>
#include <string.h>
int main()
{
    char str[100];
    scanf("%s",str);
    for(int i=0;i<(int)strlen(str);i++)
    {   int flag1=0,flag2=0;
        if(str[i]=='i'||str[i]=='I')
        {   flag1=1;
            if(str[i+1]=='s'||str[i+1]=='S') flag2=1;
        }
        if(flag1==0&&flag2==0&&str[i-1]!='i'&&str[i-1]!='I') printf("%c",str[i]);
    }
}