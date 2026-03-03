#include <stdio.h>
#include <string.h>

// 1. judge函数：保持不变（判断是否为分隔符：非字母数字则是分隔符）
int judge(char x) {
    int flag = 1;
    // 字母（大小写）或数字：不是分隔符（flag=0）
    if ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z') || (x >= '0' && x <= '9')) {
        flag = 0;
    }
    return flag;
}

// 2. 修复count函数：统计有效子串数量（处理连续分隔符、开头/结尾分隔符）
int count(char str[], int len) {
    int valid_sep = 0;        // 有效分隔符数量（连续分隔符只算1个）
    int is_prev_sep = 1;      // 初始：认为前一个是分隔符（处理开头分隔符）
    int has_valid_char = 0;   // 标记是否有有效字符（避免全分隔符情况）

    for (int i = 0; i < len; i++) {
        if (judge(str[i]) == 1) {  // 当前是分隔符
            is_prev_sep = 1;
        } else {                    // 当前是有效字符（字母/数字）
            has_valid_char = 1;     // 标记存在有效字符
            // 前一个是分隔符 → 说明当前字符是新子串的开始，之前有1个有效分隔符
            if (is_prev_sep == 1 && i > 0) {  // i>0：排除字符串开头的有效字符
                valid_sep++;
            }
            is_prev_sep = 0;        // 更新前一个字符为有效字符
        }
    }

    // 有效子串数量 = 有效分隔符数 + 1（若有有效字符）；否则为0（全分隔符）
    return has_valid_char ? (valid_sep + 1) : 0;
}

int main() {
    char str[100];
    // 3. 用fgets替换scanf：支持读取含空格的字符串（如"apple banana"）
    fgets(str, sizeof(str), stdin);  // 读取整行（包括空格）
    int len = strlen(str);

    // 去掉fgets读取的换行符（若存在，避免换行符被误判为分隔符）
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
        len--;  // 长度减1（去掉换行符）
    }

    // 统计有效子串数量（已处理连续分隔符）
    int num = count(str, len);

    // 将所有分隔符替换为'\0'（分割子串）
    for (int i = 0; i < len; i++) {
        if (judge(str[i]) == 1) {
            str[i] = '\0';
        }
    }

    // 4. 修复遍历输出：跳过空串，只输出有效子串
    char *p = str;  // 指针遍历字符串
    int k = 0;      // 已输出的子串计数

    while (k < num) {  // 只输出到有效子串数量为止
        // 步骤1：跳过开头的连续'\0'（空串）
        while (*p == '\0' && p < str + len) {
            p++;
        }
        // 步骤2：若已到字符串末尾，退出（避免越界）
        if (*p == '\0') {
            break;
        }
        // 步骤3：输出当前有效子串
        printf("%s\n", p);
        k++;  // 已输出子串计数+1
        // 步骤4：跳过当前子串后的连续'\0'（准备下一个子串）
        while (*p != '\0') {
            p++;
        }
    }

    return 0;
}