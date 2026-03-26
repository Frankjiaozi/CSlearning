#include <stdio.h>
#include <string.h>
#include <ctype.h>  // 提供isdigit()函数，用于判断字符是否为数字

int main() {
    // 定义足够大的字符数组存储输入（支持包含空格的整行输入）
    char str[1000];
    // 使用fgets读取整行输入（包括空格），避免scanf("%s")截断空格的问题
    fgets(str, sizeof(str), stdin);
    
    // 处理fgets读取的换行符（fgets会把回车符\n也读入，需要替换为字符串结束符）
    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
    
    int i = 0;
    // 遍历字符串的每个字符
    while (str[i] != '\0') {
        // 检测到数字字符，开始提取连续的整数
        if (isdigit(str[i])) {
            int start = i;  // 记录当前数字段的起始位置
            // 向后遍历，直到遇到非数字字符，确定数字段的结束位置
            while (str[i] != '\0' && isdigit(str[i])) {
                i++;
            }
            // 输出当前提取到的完整整数
            for (int j = start; j < i; j++) {
                printf("%c", str[j]);
            }
            // 输出四个空格（严格匹配题目要求的分隔符）
            printf("    ");
        } else {
            // 非数字字符，直接跳过
            i++;
        }
    }
    
    return 0;
}