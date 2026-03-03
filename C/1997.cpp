#include <stdio.h>
#include <string.h>
int main()
{
    char str[100];
    int m;
scanf("%[^\n]",str);
getchar();
scanf("%d",&m);
int n=(int)strlen(str);
if(n>=m)
{
for(int i=m-1;i<(int)strlen(str);i++)
{
   printf("%c",str[i]);
}

}
else printf("%s","Data error!");



}