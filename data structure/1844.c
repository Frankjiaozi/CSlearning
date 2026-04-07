#include <stdio.h>
#include <stdlib.h>

// 定义链表节点
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// 判断数据是否已在链表中（去重用）
int isExist(Node *head, int val) {
    Node *p = head->next;
    // 循环链表遍历终止条件：回到头结点
    while (p != head) {
        if (p->data == val)
            return 1;
        p = p->next;
    }
    return 0;
}

// 按升序插入节点（带重复判断）
void insertSort(Node *head, int val) {
    // 重复数据直接跳过
    if (isExist(head, val))
        return;

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = val;

    Node *p = head;
    // 找到插入位置：p的下一个节点值 > 当前值 或 遍历到尾部
    while (p->next != head && p->next->data < val) {
        p = p->next;
    }

    // 插入新节点
    newNode->next = p->next;
    p->next = newNode;
}

// 打印循环链表
void printList(Node *head) {
    Node *p = head->next;
    while (p != head) {
        printf("%d", p->data);
        if(p->next!=head)
        {
            printf(" ");
        }
        p = p->next;
    }
}

int main() {
    // 1. 创建头结点（循环链表：头结点next指向自己）
    Node *head = (Node *)malloc(sizeof(Node));
    head->next = head;

    int num;
    // 持续读取输入数据，直到输入结束
    while (scanf("%d", &num) != EOF) {
        insertSort(head, num);
        
    }

    // 输出结果
    printList(head);
    return 0;
}