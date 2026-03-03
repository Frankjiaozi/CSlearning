#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 7进制整数部分加1（处理进位）
void increment_base7(char *int_part) {
    int len = strlen(int_part);
    int i = len - 1;
    int carry = 1; // 初始进位值为1
    
    while (i >= 0 && carry) {
        if (int_part[i] < '6') {
            int_part[i]++;  // 当前位+1
            carry = 0;      // 进位结束
        } else {            // 当前位是'6'
            int_part[i] = '0';  // 6+1=7，变为0，继续进位
            carry = 1;
            i--;            // 处理前一位
        }
    }
    
    // 如果进位到最前面还有进位，需要扩展一位
    if (carry) {
        memmove(int_part + 1, int_part, len + 1); // 移动字符串（包括'\0'）
        int_part[0] = '1';  // 最高位置1，如 6+1 → 10， 66+1 → 100
    }
}

int main() {
    char input[100];
    char int_part[100];
    char frac_part[10];
    
    while (scanf("%s", input) != EOF) {
        // 分割整数和小数部分
        char *dot = strchr(input, '.');
        
        if (!dot) {
            // 没有小数点，直接原样输出
            printf("%s\n", input);
            continue;
        }
        
        // 提取整数部分
        int int_len = dot - input;
        strncpy(int_part, input, int_len);
        int_part[int_len] = '\0';
        
        // 提取小数部分
        strcpy(frac_part, dot + 1);
        
        // 确保小数部分至少有4位（不足补0）
        int frac_len = strlen(frac_part);
        if (frac_len < 4) {
            for (int i = frac_len; i < 4; i++) {
                frac_part[i] = '0';
            }
            frac_part[4] = '\0';
            frac_len = 4;
        }
        
        // 取前3位作为结果
        char result_frac[5];
        strncpy(result_frac, frac_part, 3);
        result_frac[3] = '\0';
        
        // "3舍4入"：判断第4位是否≥4
        if (frac_len >= 4 && frac_part[3] >= '4') {
            // 需要进位，从第3位开始向前处理
            int i = 2;  // 第3位的索引（0-based）
            int carry = 1;
            
            while (i >= 0 && carry) {
                if (result_frac[i] < '6') {
                    result_frac[i]++;  // 当前位+1
                    carry = 0;         // 进位结束
                } else {               // 当前位是'6'
                    result_frac[i] = '0';  // 6+1=7，变为0，继续进位
                    carry = 1;
                    i--;               // 处理前一位
                }
            }
            
            // 如果进位到小数点前
            if (carry) {
                increment_base7(int_part);
            }
        }
        
        // 输出结果
        printf("%s.%s\n", int_part, result_frac);
    }
    
    return 0;
}