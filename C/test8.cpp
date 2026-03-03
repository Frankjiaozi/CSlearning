#include <stdio.h>
#include <string.h>
int main()
{
char str[100];
char a[100];
scanf("%s",str);
//int flag=1;
for(int i=0;i<strlen(str);i++)
{
    for(int j=i+1;j<strlen(str);j++)
    {
    if(str[i]==str[j])    {
            a[0]=str[i];  
    }
    }
if(strlen(a)==0) printf("NO\n");
else printf("%c\n",a[0]);
//if(flag==0) break;
}
}

