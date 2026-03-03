#include <stdio.h>
#include <string.h>
int main()
{
    char str[100];
    scanf("%s",str);
    for(int i=0;i<strlen(str);i++)
    {
        for(int j=i+1;j<strlen(str);j++)
        {
            if(str[i]==str[j]) break;
            else printf("%c",str[i]);
        }
    }
}