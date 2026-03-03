#include <stdio.h>
#include <stdlib.h>  // 用于malloc/free（替代变长数组）

// 1. 定义结构体（可通过typedef简化类型名，避免重复写struct）
typedef struct Point
{
    int x;
    int y;
} Point;  // 此后可直接用Point作为类型，无需struct

typedef struct Vector
{
    int x;
    int y;
} Vector;  // 同理，直接用Vector作为类型

// 向量运算：由两点生成边向量（point1→point2）
Vector vector_cal(Point point1, Point point2)
{
    Vector vector_temp;
    vector_temp.x = point2.x - point1.x;
    vector_temp.y = point2.y - point1.y;
    return vector_temp;
}

// 叉积运算：vector1 × vector2（判断转向，符号表示方向）
int cross(Vector vector1, Vector vector2)
{
    return vector1.x * vector2.y - vector1.y * vector2.x;
}

// 判断所有叉积是否同号（凸多边形核心逻辑）
// 无需用product相乘（避免溢出），直接判断符号一致性
int is_convex(Point* points, int n)
{
    if (n < 3) return 0;  // 少于3个点，不是多边形

    // 2. 用动态内存（堆）替代变长数组，避免栈溢出和兼容性问题
    Vector* vectors = (Vector*)malloc(n * sizeof(Vector));
    if (vectors == NULL) return -1;  // 内存分配失败

    // 3. 完整初始化n条边向量（包含最后一条n-1→0）
    for (int i = 0; i < n; i++)
    {
        Point p1 = points[i];
        Point p2 = points[(i + 1) % n];  // (i+1)%n 自动处理n-1→0
        vectors[i] = vector_cal(p1, p2);
    }

    // 4. 判断所有相邻边向量的叉积符号是否一致
    int sign = 0;  // 记录第一个非零叉积的符号
    for (int i = 0; i < n; i++)
    {
        int cp = cross(vectors[i], vectors[(i + 1) % n]);
        if (cp != 0)  // 跳过共线情况（严格凸多边形无共线）
        {
            if (sign == 0)
                sign = cp > 0 ? 1 : -1;  // 初始化符号
            else if (cp * sign < 0)  // 出现相反符号，说明是凹多边形
            {
                free(vectors);  // 释放内存
                return 0;
            }
        }
    }

    free(vectors);  // 释放内存
    return 1;  // 所有叉积同号，是凸多边形
}

int main()
{
    int n;
    // 输入顶点数，过滤n=0、n=1、n=2的无效情况
    while (scanf("%d", &n) != EOF && n >= 3)
    {
        // 动态分配顶点数组（堆内存，支持大n）
        Point* points = (Point*)malloc(n * sizeof(Point));
        if (points == NULL)
        {
            printf("内存分配失败\n");
            continue;
        }

        // 输入每个顶点的坐标
        for (int i = 0; i < n; i++)
        {
            scanf("%d %d", &points[i].x, &points[i].y);
        }

        // 判断并输出结果
        int result = is_convex(points, n);
        if (result == 1)
            printf("convex\n");
        else if (result == 0)
            printf("concave\n");
        else
            printf("错误\n");

        free(points);  // 释放顶点数组内存
    }

    // 若输入n<3，提示无效
    if (n > 0 && n < 3)
        printf("无效多边形：至少需要3个顶点\n");

    return 0;
}