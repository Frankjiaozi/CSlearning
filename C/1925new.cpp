#include <stdio.h>
int main()
{getchar();
char str[21]={0};
int eng=0,num=0,spa=0,oth=0;
for(int i=0;i<20;i++)
{char ch={0};
ch=getchar();
if ((ch<='z'&&ch>='a')||(ch<='Z'&&ch>='A')) eng+=1;
else if(ch<='9'&&ch>='0') num+=1;
else if(ch==' '||ch=='\n') spa+=1;
}
spa=spa-1;
oth=20-spa-num-eng;
printf("%d个英文字母\n%d个数字字符\n%d个空格或回车\n%d个其他字符\n",eng,num,spa,oth);
}