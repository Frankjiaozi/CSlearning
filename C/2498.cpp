#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    // 计算10的k次方（k是n的位数）
    int k = 1, temp = n;
    while (temp > 0) {
        k *= 10;
        temp /= 10;
    }
    
    // 判断n^2 % k是否等于n
    if ((long long)n * n % k == n) {
        printf("是守形数\n");
    } else {   
        printf("不是守形数\n");
    }
    return 0;
} 