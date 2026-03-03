#include <stdio.h>
#include <string.h>
int main()
{
    
char str[21]={0};
int count=0;
int eng=0,num=0,spa=0,oth=0;
//while(fgets(str,sizeof(str),stdin)!=NULL)
while(count<20)
{str[count]=getchar();

count++;}
for(int i=0;i<strlen(str);i++)
{
if((str[i]<='z'&&str[i]>='a')||(str[i]>='A'&&str[i]<='Z')) eng=eng+1;
if(str[i]>=48 && str[i]<=57) num=num+1;
if(str[i]==32||str[i]==13) spa=spa+1;
}
oth=strlen(str)-eng-num-spa;
printf("%d个英文字母\n%d个数字字符\n%d个空格或回车\n%d个其他字符\n",eng,num,spa,oth);

return 0;
}