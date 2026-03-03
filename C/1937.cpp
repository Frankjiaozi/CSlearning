#include <stdio.h>
#include <math.h>
#include <stdio.h>

// 判断一个数是否为回文数
int huiwen(int a) {
    // 处理负数（题目中可能不涉及，但为了健壮性）
    if (a < 0) {
        return 0;
    }
    
    // 提取数字的每一位
    int digits[10]; // 假设最大不超过10位数
    int count = 0;
    int temp = a;
    
    // 特殊处理0的情况
    if (temp == 0) {
        digits[count++] = 0;
    } else {
        while (temp > 0) {
            digits[count++] = temp % 10;
            temp /= 10;
        }
    }
    
    // 检查回文
    for (int i = 0; i < count / 2; i++) {
        if (digits[i] != digits[count - 1 - i]) {
            return 0;
        }
    }
    return 1;
}


int main()
{
int a;
scanf("%d",&a);
if(huiwen(a)==1&&huiwen(a*a)==1&&huiwen(a*a*a)==1) printf("%d是三重回文数",a);
else printf("%d不是三重回文数",a);



}