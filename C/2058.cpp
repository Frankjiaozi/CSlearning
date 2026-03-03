//进制转换
//输入一个十进制数N，将它转换成R进制数输出


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 手动实现字符串反转（替换strrev）
void reverseStr(char str[]) {
    int len = strlen(str);
    int left = 0, right = len - 1;
    while (left < right) {
        // 交换左右字符
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;
        left++;
        right--;
    }
}
int decimalToN(int decimal, int n, char result[]) {
    // 1. 检查目标进制是否合法（11~36）
    if (n < 11 || n > 36) {
        printf("错误:目标进制n必须在11~36之间!\n");
        return -1;
    }

    // 2. 处理十进制数为0的特殊情况（直接返回"0"）
    if (decimal == 0) {
        result[0] = '0';
        result[1] = '\0';  // C语言字符串必须以'\0'结尾
        return 0;
    }

    // 3. 处理负数：标记是否为负数，然后转换绝对值
    int isNegative = 0;  // 0=正数，1=负数
    if (decimal < 0) {
        isNegative = 1;
        decimal = -decimal;  // 转为绝对值计算
    }

    // 4. 核心：除n取余，存储余数对应的字符（低位→高位）
    int index = 0;  // 字符数组的下标，记录当前存储位置
    while (decimal > 0) {
        int remainder = decimal % n;  // 取余数（0~n-1）
        // 余数映射为字符：0~9→'0'~'9'，10~35→'A'~'Z'
        if (remainder <= 9) {
            result[index++] = '0' + remainder;  // 数字字符
        } else {
            result[index++] = 'A' + remainder - 10;  // 字母字符（10→A，11→B...）
        }
        decimal = decimal / n;  // 更新商，继续循环
    }

    // 5. 若原数是负数，在结果前加负号
    if (isNegative) {
        result[index++] = '-';
    }

    // 6. 给字符串加结束标记
    result[index] = '\0';

    // 7. 反转字符串（余数是低位→高位存储，反转后才是正确顺序）
    reverseStr(result);

    return 0;
}






int main()
{   //输入
    int n,m;
    int arr[100];
while(scanf("%d %d",&n,&m)!=EOF)
{int count=0;
//进制小于9
if(m<=9)
{
    int p=n;
    int k=0;
    int rest=n;
    if(n>0){
    while(p>=1)
    {  
     
        rest=p%m;
        p=p/m;
        arr[k]=rest;
        k++;
        count++;
    }
    //输出
    for(int i=count-1;i>=0;i--)
    {
        printf("%d",arr[i]);
        if(i==0) printf("\n");
    }}

//fuhs
    if(n<0)
    {
    n=abs(n);
    p=n;
    k=0;
    rest=n;
    while(p>=1)
    {  
     
        rest=p%m;
        p=p/m;
        arr[k]=rest;
        k++;
        count++;
    }
    //输出
    printf("-");
    for(int i=count-1;i>=0;i--)
    {
        printf("%d",arr[i]);
        if(i==0) printf("\n");
    }}
}

//进制大于9
if(m>=11)
{   char result[1000];
    decimalToN(n,m,result);
    printf("%s\n",result);
}
}
}