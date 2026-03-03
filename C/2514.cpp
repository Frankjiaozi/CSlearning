#include <stdio.h>

// 定义棍子结构体，存储长度、直径、编码
typedef struct {
    int length;
    int diameter;
    long long code;  // 编码是9位整数，用long long避免溢出
} Stick;

int main() {
    int N;
    scanf("%d", &N);  // 读取测试数据组数
    
    while (N--) {
        int m;
        scanf("%d", &m);  // 读取每组的棍子数量
        Stick sticks[1000];  // 存储最多1000根棍子
        
        // 读取m根棍子的信息
        for (int i = 0; i < m; i++) {
            scanf("%d %d %lld", &sticks[i].length, &sticks[i].diameter, &sticks[i].code);
        }
        
        // 步骤1：找最长长度
        int max_len = sticks[0].length;
        for (int i = 1; i < m; i++) {
            if (sticks[i].length > max_len) {
                max_len = sticks[i].length;
            }
        }
        
        // 步骤2：在最长长度中找最细直径
        int min_dia = -1;  // 初始化为-1，表示未找到
        for (int i = 0; i < m; i++) {
            if (sticks[i].length == max_len) {
                if (min_dia == -1 || sticks[i].diameter < min_dia) {
                    min_dia = sticks[i].diameter;
                }
            }
        }
        
        // 步骤3：在最长且最细的棍子中找最大编码
        long long max_code = 0;
        for (int i = 0; i < m; i++) {
            if (sticks[i].length == max_len && sticks[i].diameter == min_dia) {
                if (sticks[i].code > max_code) {
                    max_code = sticks[i].code;
                }
            }
        }
        
        // 输出9位编码（题目保证编码为9位，直接输出即可）
        printf("%09lld\n", max_code);
    }
    
    return 0;
}