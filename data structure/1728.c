#include <stdio.h>
#include <stdlib.h>

struct Node {
    int x;
    struct Node* next;
};

// 打印链表（严格匹配格式：无末尾空格，仅输出节点值）
void printNode(struct Node* head) {
    struct Node* p = head;
    if (p == NULL) return;
    // 第一个节点直接输出，后续节点前加空格，避免末尾多余空格
    printf("%d", p->x);
    p = p->next;
    while (p != NULL) {
        printf(" %d", p->x);
        p = p->next;
    } 
    //printf("\n"); 
}

// 创建链表（仅读取输入，无任何输出）
struct Node* create(int n) {
    struct Node* head = NULL;
    struct Node* pnew = NULL;
    struct Node* end = NULL;
    
    for (int i = 0; i < n; i++) {
        pnew = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &pnew->x);
        pnew->next = NULL;
        
        if (head == NULL) {
            head = pnew;
            end = pnew;
        } else {
            end->next = pnew;
            end = pnew;
        }
    }
    return head;
}

// 核心算法：交换第k个节点（P）与其后继节点（k从1开始计数）
struct Node* swapPAndNext(struct Node* head, int k) {
    // 边界检查1：链表为空/只有1个节点，无法交换
    if (head == NULL || head->next == NULL) {
        return head;
    }
    // 边界检查2：k小于1（无效位置）
    if (k < 1) {
        return head;
    }

    struct Node* pre = NULL;  // P的前驱节点
    struct Node* P = head;    // 第k个节点（目标节点）
    int count = 1;            // 计数（从1开始）

    // 步骤1：找到第k个节点P及其前驱pre
    while (P != NULL && count < k) {
        pre = P;
        P = P->next;
        count++;
    }

    // 边界检查3：k超过链表长度，或P是最后一个节点（无后继）
    if (P == NULL || P->next == NULL) {
        return head;
    }

    // 步骤2：P的后继节点Q
    struct Node* Q = P->next;

    // 步骤3：调整指针完成交换
    if (pre == NULL) {
        // P是头节点（k=1），更新头指针
        head = Q;
    } else {
        // P是中间节点，前驱指向Q
        pre->next = Q;
    }
    P->next = Q->next;  // P指向Q的后继，避免链表断裂
    Q->next = P;        // Q指向P

    return head;
}

// 完整的main函数（无语法错误）
int main() {
    int n, k;
    // 读取链表长度
    scanf("%d", &n);
    // 创建链表（读取n个节点值）
    struct Node* head = create(n);
    // 读取P指向的节点位置（第k个，从1开始）
    scanf("%d", &k);
    // 交换P与其后继节点
    head = swapPAndNext(head, k);
    // 打印交换后的链表（仅输出节点值，无多余内容）
    printNode(head);

    // 释放链表内存（无输出，避免内存泄漏）
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}