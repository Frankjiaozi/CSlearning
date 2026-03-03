#include <stdio.h>
#include <string.h>

void sort(char str[])
{
    int len=strlen(str);
    for(int i=0;i<len-1;i++)
    {
        for(int j=0;j<len-1-i;j++)
        {
            if(str[j]>str[j+1])
            {
                char temp=str[j];
                str[j]=str[j+1];
                str[j+1]=temp;
            }
        }
    }
}

int main()
{
char str1[100];
char str2[100];
while(scanf("%s %s",str1,str2)!=EOF)
{
    strcat(str1,str2);
    sort(str1);

    printf("%s\n",str1);
}
}