#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 跳过空格（你的代码，完全保留）
void skip_space(char *str,int *pos)
{
    while(str[*pos]==' ')
    {
        (*pos)++;
    }
}

// 判断是否为数字（你的代码，完全保留）
int isdigit(char c)
{
    if(c>='0'&&c<='9')
    {
        return 1;
    }
    return 0;
}

// 读取数字（你的代码，完全保留）
int getnum(char str[],int *pos)
{
    int num=0;
    while(isdigit(str[*pos]))
    {
        num = num*10 + (str[*pos]-'0');
        (*pos)++;
    }
    return num;
}

// ? 修复核心：cal 递归计算函数
int cal(char *str,int *pos)
{
    skip_space(str, pos);  

    // 情况1：遇到左括号 ( → 解析子表达式
    if(str[*pos] == '(')
    {
        (*pos)++;        
        skip_space(str, pos);

        // 1. 读取运算符 +-*/，并移动指针
        char op = str[*pos];
        (*pos)++; 
        skip_space(str, pos);

        // 2. 读取第一个操作数（数字/嵌套表达式）
        int result;
        if(isdigit(str[*pos])){
            result = getnum(str, pos);
        } else {
            result = cal(str, pos); // 嵌套表达式，递归计算
        }

        // 3. 循环读取所有剩余操作数，依次计算（支持多操作数）
        while(1)
        {
            skip_space(str, pos);
            if(str[*pos] == ')') break; // 遇到右括号，结束

            // 读取当前操作数（数字/递归）
            int val;
            if(isdigit(str[*pos])){
                val = getnum(str, pos);
            } else {
                val = cal(str, pos);
            }

            // 4. 依次运算（写在循环内，支持连加/连乘）
            switch(op)
            {
                case '+': result += val; break;
                case '-': result -= val; break;
                case '*': result *= val; break;
                case '/': result /= val; break;
            }
        }

        (*pos)++; // 跳过右括号 )
        return result;
    }

    // 情况2：遇到数字 → 直接返回数字
    return getnum(str, pos);
}

// ? 修复：main 函数输入+调用
int main()
{
    char str[100];
    fgets(str, sizeof(str), stdin); // 读整行，支持空格
    int pos=0;
    int result = cal(str, &pos);
    printf("%d", result);
    return 0;
}