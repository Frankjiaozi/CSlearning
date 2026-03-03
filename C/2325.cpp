#include <stdio.h>
#include <string.h>

#define MAX_LEN 405
#define MAX_RESULT 1000

// 反转字符串
void reverse(char *str) {
    int len = strlen(str);
    char temp;
    for (int i = 0; i < len / 2; i++) {
        temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

// 去除小数末尾的零
void trimTrailingZeros(char *decimal) {
    int len = strlen(decimal);
    int i;
    for (i = len - 1; i >= 0; i--) {
        if (decimal[i] != '0') {
            break;
        }
    }
    decimal[i + 1] = '\0';
}

int main() {
    char A[MAX_LEN], B[MAX_LEN];
    
    while (scanf("%s %s", A, B) != EOF) {
        char intA[MAX_LEN] = {0}, intB[MAX_LEN] = {0};
        char decA[MAX_LEN] = {0}, decB[MAX_LEN] = {0};
        
        // 分割整数部分和小数部分
        char *dotA = strchr(A, '.');
        char *dotB = strchr(B, '.');
        
        if (dotA) {
            *dotA = '\0';
            strcpy(intA, A);
            strcpy(decA, dotA + 1);
        } else {
            strcpy(intA, A);
            decA[0] = '0';
        }
        
        if (dotB) {
            *dotB = '\0';
            strcpy(intB, B);
            strcpy(decB, dotB + 1);
        } else {
            strcpy(intB, B);
            decB[0] = '0';
        }
        
        // 对齐小数部分（补零）
        int decLen = strlen(decA) > strlen(decB) ? strlen(decA) : strlen(decB);
        char tempA[MAX_LEN] = {0}, tempB[MAX_LEN] = {0};
        
        strcpy(tempA, decA);
        strcpy(tempB, decB);
        
        // 在末尾补零
        while (strlen(tempA) < decLen) {
            strcat(tempA, "0");
        }
        while (strlen(tempB) < decLen) {
            strcat(tempB, "0");
        }
        
        // 小数部分相加
        char resultDec[MAX_RESULT] = {0};
        int carry = 0, i, j, k = 0;
        
        reverse(tempA);
        reverse(tempB);
        
        for (i = 0; i < decLen; i++) {
            int sum = (tempA[i] - '0') + (tempB[i] - '0') + carry;
            resultDec[k++] = sum % 10 + '0';
            carry = sum / 10;
        }
        resultDec[k] = '\0';
        reverse(resultDec);
        
        // 整数部分相加
        reverse(intA);
        reverse(intB);
        
        char resultInt[MAX_RESULT] = {0};
        k = 0;
        
        int intLen = strlen(intA) > strlen(intB) ? strlen(intA) : strlen(intB);
        
        for (i = 0; i < intLen; i++) {
            int dA = i < strlen(intA) ? intA[i] - '0' : 0;
            int dB = i < strlen(intB) ? intB[i] - '0' : 0;
            int sum = dA + dB + carry;
            resultInt[k++] = sum % 10 + '0';
            carry = sum / 10;
        }
        
        if (carry > 0) {
            resultInt[k++] = carry + '0';
        }
        resultInt[k] = '\0';
        reverse(resultInt);
        
        // 去除小数部分末尾的零
        trimTrailingZeros(resultDec);
        
        // 输出结果
        if (strcmp(resultDec, "") == 0 || strcmp(resultDec, "0") == 0) {
            printf("%s\n", resultInt);
        } else {
            printf("%s.%s\n", resultInt, resultDec);
        }
    }
    
    return 0;
}