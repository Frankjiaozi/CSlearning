#include <stdio.h>
#include <string.h>
int main()
{
char str[100]={0};
scanf("%[^\n]",str);
getchar();
char ch='0';
scanf("%c",&ch);
//printf("%d",result);
 for(int i=0;i<strlen(str);i++)
{
      {if(ch!='\n')
      {if(str[i]!=ch) printf("%c",str[i]);}
    else if(ch=='\n')
      {
        if(str[i]!=' ') printf("%c",str[i]);
      }}
  }
//printf("\n%c",ch);
}
