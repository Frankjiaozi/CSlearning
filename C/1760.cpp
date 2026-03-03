#include <stdio.h>
#include <string.h>
#include <ctype.h>
int judge(char str[],int len)
{   int flag=0;
    for(int i=0;i+3<len;i++)
    {
        if(str[i]=='s'&&str[i+1]=='a'&&str[i+2]=='l'&&str[i+3]=='t') flag=1;
    }
    return flag;
}
int main()
{
char str[100];
char lowstr[100];
while (fgets(str,99,stdin)!=NULL)
{   
    str[strcspn(str,"\n")]='\0';
    for(int i=0;i<100;i++)
    {
        lowstr[i]=tolower((unsigned char)str[i]);
    }
    lowstr[strcspn(lowstr,"\n")]='\0';
    int len=(int)strlen(lowstr);
        int result=judge(lowstr,len);
        if(result==1) printf("%s\n",str);
    


}


}