#include <stdio.h>
#include <string.h>
int main()
{
char str[100];
char str1[100];
scanf("%s",str);
int j=0;
for(int i=strlen(str)-1;i>=0;i--)  {   
str1[j]=str[i];
j++;
}
for(int i=0;i<strlen(str);i++)
{
    str[i]=str1[i];
}
printf("%s\n",str);
}