#include <stdio.h>
#include <string.h>
char c;
char trans(char c)
{
if(c>='A'&&c<'Z') 
{
    c=c+33;
}
else if(c=='Z') c='a';
else if(c>='a'&&c<='z')
{
    if(c>='a'&&c<='c') c='2';
    else if(c>='d'&&c<='f') c='3';
    else if(c>='g'&&c<='i') c='4';
    else if(c>='j'&&c<='l') c='5';
    else if(c>='m'&&c<='o') c='6';
    else if(c>='p'&&c<='s') c='7';
    else if(c>='t'&&c<='v') c='8';
    else c='9';
}
else c=c;
return c;
}

int main()
{
char str[100];
while(scanf("%s",str)!=EOF)
    {int i=0;
        for(;i<strlen(str);i++)
    {
        printf("%c",trans(str[i]));
    
    }
printf("\n");
}


    return 0;
}