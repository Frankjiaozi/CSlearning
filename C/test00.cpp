#include <stdio.h>
#include <string.h>

int main() {
    char dest[20]; // 目标缓冲区大小为 20
    const char *src = "Hello, World!";

    // 使用 strcpy_s 将 src 复制到 dest
    if (strcpy_s(dest, sizeof(dest), src) != 0) {
        printf("strcpy_s failed!\n");
        return 1; // 返回错误代码
    } else {
        printf("After strcpy_s: %s\n", dest);
    }

    // 使用 strcat_s 将 " C Language" 追加到 dest
    const char *appendStr = " C Language";
    if (strcat_s(dest, sizeof(dest), appendStr) != 0) {
        printf("strcat_s failed!\n");
        return 1; // 返回错误代码
    } else {
        printf("After strcat_s: %s\n", dest);
    }

    return 0;
}