#include <stdio.h>
#include <string.h>

int find(char x,char str[])
{   int flag=0;
    for(int i=0;i<(int)strlen(str);i++)
    {
        if(str[i]==x)
        {
            flag=1;
            break;
        }
    }
    return flag;
}


int judge(char str_sub[], char str_target[]) 
{
    int len_sub = strlen(str_sub);
    int len_target = strlen(str_target);
    int i = 0, j = 0; // i遍历子序列，j遍历目标序列

    // 双指针遍历：顺序匹配字符
    while (i < len_sub && j < len_target) {
        if (str_sub[i] == str_target[j]) {
            i++; // 匹配到，子序列指针后移
        }
        j++; // 无论是否匹配，目标序列指针都后移
    }

    // 若i遍历完子序列，说明是子序列
    return i == len_sub ? 1 : 0;
}

int main()
{   int count = 0;
    int n;
scanf("%d",&n);
char str[n][100];
for(int i=0;i<n;i++)
{
    scanf("%s",str[i]);
}
for(int i=0;i<n;i++) //koaspco jiaozi doiejdkl
{
    for(int j=i+1;j<n;j++)
    {
        if(judge(str[i],str[j])==1)
        {
            count++;
        }
    }
}
printf("%d",count);
}