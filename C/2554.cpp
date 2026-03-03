#include <stdio.h>
#include <string.h>

int n, L;
char dict[28] = " ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char str[100] = {0};
int count = 0;    // 统计「有效困难串」的个数
int found = 0;    // 标记是否找到第n个，终止所有递归

// 你的ishard函数（无需修改）
int ishard(char *s) {
    int len = strlen(s);
    if (len == 0) return 1;
    for (int k = 1; k <= len / 2; k++) {
        int equal = 1;
        for (int i = 0; i < k; i++) {
            if (s[len - 2*k + i] != s[len - k + i]) {
                equal = 0;
                break;
            }
        }
        if (equal == 1) return 0;
    }
    return 1;
}

void dfs(int pos) {
    if (found) return;  // 找到目标，直接退出所有递归

    // 核心：只有「非空串+是困难串」，才是有效串，计数+1
    if (pos > 0 && ishard(str) == 1) {
        count++;
        // 找到第n个，输出并标记结束
        if (count == n) { 
            printf("%s\n", str);
            found = 1;
            return;
        }
    }

    // 遍历前L个字母（A~第L个）
    for (int i = 1; i <= L; i++) {
        str[pos] = dict[i];  // 拼接当前字符
        // 只有新串是困难串，才继续递归（避免无效递归）
        if (ishard(str) == 1) {
            dfs(pos + 1);
        }
        if (found) return;  // 找到后快速退出
    }
}

int main() {
    scanf("%d %d", &n, &L);
    dfs(0);  // 从pos=0开始，自动拼接第一个字符（无需手动初始化str[0]）
    return 0;
}