#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 交换两个字符串指针的函数
void swap(char **a, char **b) {
    char *temp = *a;
    *a = *b;
    *b = temp;
}

int main() 
{
    // 存储5个学生编号的字符串指针数组
    char *nums[5];
    
    // 为每个编号分配内存（长度不超过100，故分配101字节存字符和'\0'）
    for (int i = 0; i < 5; i++) {
        nums[i] = (char *)malloc(101 * sizeof(char));
    }
    for (int i = 0; i < 5; i++) {
        fgets(nums[i], 101, stdin);
        // 移除字符串末尾的换行符
        nums[i][strcspn(nums[i], "\n")] = '\0';
    }
    
    // 冒泡排序（字典序降序）
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4 - i; j++) {
            if (strcmp(nums[j], nums[j + 1]) < 0) {
                swap(&nums[j], &nums[j + 1]);
            }
        }
    }
    
    // 交换最大编号（第一个）和最小编号（最后一个）
    swap(&nums[0], &nums[4]);
    
    // 输出结果
    for (int i = 0; i < 5; i++) {
        printf("%s\n", nums[i]);
    }
    
    // 释放动态分配的内存
    for (int i = 0; i < 5; i++) {
        free(nums[i]);
    }
    
    return 0;
}