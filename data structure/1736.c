#include <stdio.h>
#include <string.h>

// 定义考生结构体，存储姓名和三门分数
struct Student {
    char name[20];  // 姓名（兼容无空格的输入格式）
    double score1;  // 第一门分数（double适配%lf输入）
    double score2;  // 第二门分数
    double score3;  // 第三门分数
};

int main() {
    int n;
    // 输入学生总数
    scanf("%d", &n);
    
    // 结构体数组存储所有考生信息（线性表核心实现）
    struct Student students[n];
    
    // 循环输入每个考生的姓名和三门分数
    for (int i = 0; i < n; i++) {
        // %s自动跳过空格，%lf匹配double类型
        scanf("%s %lf %lf %lf", 
              students[i].name, 
              &students[i].score1, 
              &students[i].score2, 
              &students[i].score3);
    }
    
    // 第一部分：输出所有通过考试的考生（总分≥180，按输入顺序）
    for (int i = 0; i < n; i++) {
        double total = students[i].score1 + students[i].score2 + students[i].score3;
        if (total >= 180.0) {
            printf("%s -- pass exam\n", students[i].name);
        }
    }
    
    // 第二部分：输出所有未通过考试的考生（总分<180，按输入顺序）
    for (int i = 0; i < n; i++) {
        double total = students[i].score1 + students[i].score2 + students[i].score3;
        if (total < 180.0) {
            printf("%s -- not pass exam\n", students[i].name);
        }
    }
    
    // 第三部分：输出所有三门分数均为100分的考生
    for (int i = 0; i < n; i++) {
        if (students[i].score1 == 100.0 && 
            students[i].score2 == 100.0 && 
            students[i].score3 == 100.0) {
            printf("%s -- 3 x 100.0\n", students[i].name);
        }
    }
    
    return 0;
}