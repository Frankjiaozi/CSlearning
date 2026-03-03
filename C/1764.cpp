#include <stdio.h>
// 定义最大字符串长度
#define MAX_LEN 100

int main() {
    char t[MAX_LEN], s[MAX_LEN];
    int pos;
    scanf("%s", t);
    scanf("%s", s);
    scanf("%d", &pos);

    int len_t = 0, len_s = 0;
    // 计算字符串 t 的长度
    while (t[len_t] != '\0') {
        len_t++;
    }
    // 计算字符串 s 的长度
    while (s[len_s] != '\0') {
        len_s++;
    }

    // 从后往前移动 s 中 pos 位置后的字符，为插入 t 腾出空间
    for (int i = len_s; i >= pos; i--) {
        s[i + len_t] = s[i];
    }

    // 将 t 插入到 s 的 pos 位置后
    for (int i = 0; i < len_t; i++) {
        s[pos + i] = t[i];
    }

    // 输出组合后的字符串
    printf("%s\n", s);

    return 0;
}