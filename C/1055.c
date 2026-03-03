 #include <stdio.h>
#include <string.h>


void key(char* x)
{
    if(*x>='a' && *x<='z') //97 98 99 100 abc def ghi jkl mno pqrs tuv wxyz
    {
        if(*x>='a' && *x<='c')
        {
            *x='2';
        }
        if(*x>='d' && *x<='f')
        {
            *x='3';
        }
        if(*x>='g' && *x<='i')
        {
            *x='4';
        }
        if(*x>='j' && *x<='l')
        {
            *x='5';
        }
        if(*x>='m' && *x<='o')
        {
            *x='6';
        }
        if(*x>='p' && *x<='s')
        {
            *x='7';
        }
        if(*x>='t' && *x<='v')
        {
            *x='8';
        }
        if(*x>='w' && *x<='z')
        {
            *x='9';
        }
    }
    else if(*x>='A' && *x<='Z')
    {   if(*x!='Z')
        {
            *x=*x+32+1;
        }
        else
        {
            *x='a';
        }
    }

}

int main()
{
    char str[200];
    while(scanf("%s",str)!=EOF)
    {
        int len=(int)strlen(str);
        for(int i=0;i<len;i++)
        {
            key(&str[i]);
        }
        printf("%s\n",str);
    }
}