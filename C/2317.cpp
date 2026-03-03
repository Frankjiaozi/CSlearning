#include <stdio.h>
#include <string.h>

int main() {
    char str1[21], str2[21];  // 预留空间给'\0'
    
    // 读取两个字符串（限制最大20字符防止溢出）
    if (scanf("%20s %20s", str1, str2) != 2) {
        printf("0\n");
        return 0;
    }
    
    // 处理空子串情况
    int len2 = strlen(str2);
    if (len2 == 0) {
        printf("0\n");
        return 0;
    }
    
    // 统计出现次数（非重叠）
    int count = 0;
    char *p = str1;
    while ((p = strstr(p, str2)) != NULL) {
        count++;
        p += len2;  // 跳过已匹配部分，避免重叠
    }
    
    printf("%d\n", count);
    return 0;
}