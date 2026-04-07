#include <stdio.h>
#include <string.h>

void reverse(char *str)
{
    int len = strlen(str);//abd
    for(int i=0;i<len/2;i++)
    {
        char temp = str[i];
        str[i] =  str[len-1-i];
        str[len-1-i] = temp;
    }
}
int main()
{
    char str[100];
    scanf("%s", str);
    int a=0;
    char s1[100];
    char s2[100];
    while(str[a]!='&')
    {
        s1[a]=str[a];
        a++;
    }
    a++;
    int b=0;
    while(str[a]!='\0')
    {
        s2[b]=str[a];
        b++;
        a++;
    }
    s2[b]='\0';
    reverse(s2);
    
    if(strcmp(s1,s2)==0)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }   
   }
