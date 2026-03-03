#include <stdio.h>//16进制字符 0-9、A-F（大写）、a-f（小写）
#include <string.h>
int trans(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0'; // 数字字符转换
    } else if (c >= 'A' && c <= 'F') {
        return 10 + (c - 'A'); // 大写字母转换
    } else if (c >= 'a' && c <= 'f') {
        return 10 + (c - 'a'); // 小写字母转换
    }
}
int main()
{char str[80];
char str_16[80];
for(int i=0;i<80;i++)
{
str[i]='0';
str_16[i]='0';
}

scanf("%s",str);
for(int i=0;i<strlen(str);i++)
{
if((str[i]>='0'&&str[i]<='9')||(str[i]>='A'&&str[i]<='F')||(str[i]>='a'&&str[i]<='f'))
{
str_16[i]=str[i];
}
}
int arr_10[(int)strlen(str_16)];//定义数组，储存10进制数字
//将字符串改为Int
int result=0;//定义结果变量
//建立16的n次方数组并初始化为1
int dic[(int)strlen(str_16)];
for(int i=0;i<(int)strlen(str_16);i++)
{
    dic[i]=1;
}
//设置数组
for(int i=0;i<(int)strlen(str_16);i++)
{
    for(int j=0;j<((int)strlen(str_16)-i-1);j++)
    {
    dic[i]=dic[i]*16;
    }
    printf("%d ",dic[i]);
}
printf("\n");

for(int i=0;i<((int)strlen(str_16));i++)
{
arr_10[i]=trans(str_16[i]);
printf("%d",arr_10[i]);
}
printf("\n");
//得出result
for(int i=0;i<((int)strlen(str_16));i++)
{
result=result+arr_10[i]*dic[i];
}
printf("%d",result);

}