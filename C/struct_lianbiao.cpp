#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//定义结构体
struct Student
{
    int num;
    int age;
    struct Student *next;
};
typedef struct Student Student;
//定义建立链表的函数
Student *create()
{   int n=0;
    Student *p1=NULL,*p2=NULL,*head=NULL;
//输入第一个节点的数据
// 1. 为第一个节点分配内存（申请一块能存Student结构体的空间）
p1 = (Student*)malloc(sizeof(Student));  
// 2. 检查内存是否分配成功（关键！原代码没做）
if (p1 == NULL)  // 若内存不足，malloc返回NULL
{
    printf("内存分配失败！\n");
    return NULL;
}
// 3. 给第一个节点输入数据（用户输入：101 20）
scanf("%d %d", &p1->num, &p1->age);  
// 4. 第一个节点的next设为NULL（暂时没有下一个节点，标记为尾部）
p1->next = NULL;



while (p1->num != 0)  // 循环条件：新节点num≠0时才加入链表
    {
        n++;
        if (n == 1)  // 第一个有效节点作为头节点
            head = p1;
        else  // 后续节点链接到尾部
            p2->next = p1;
        
        p2 = p1;  // p2移动到新的尾节点
        // 2. 为下一个节点分配内存
        p1 = (Student*)malloc(sizeof(Student));
        if (p1 == NULL)
        {
            printf("内存分配失败！\n");
            return head;  // 至少返回已创建的部分链表
        }
        scanf("%d %d", &p1->num, &p1->age);  
        p1->next = NULL;
    }


}
int main()
{
create();
}