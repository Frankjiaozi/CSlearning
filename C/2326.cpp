#include <stdio.h>
#include <string.h>
int main()
{   char str[100];
    while(scanf("%s",str)!=EOF)
    {
        char str_temp[100];
        int len=(int)strlen(str);
        int k=0;
        for(int i=len-1;i>=0;i--)
        {
            str_temp[k]=str[i];
            k++;
        }
        str_temp[len]='\0';
        int result=strcmp(str,str_temp);
        (result==0)?puts("Yes"):puts("No");
    }
}