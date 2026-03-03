#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

/* 尾插法建立一条递增有序链表，返回头指针 */
Node *createList(int n) {
    Node *head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        Node *p = (Node *)malloc(sizeof(Node));
        p->data = x;
        p->next = NULL;
        if (!head) head = tail = p;
        else { tail->next = p; tail = p; }
    }
    return head;
}

/* 将两条递增有序链表归并成一条递减有序链表，返回新链表头指针 */
Node *mergeReverse(Node *ha, Node *hb) {
    Node *hc = NULL;          /* 结果链表头，初始为空 */
    Node *pa = ha, *pb = hb;  /* 当前扫描指针 */
    while (pa && pb) {
        Node *smaller;
        if (pa->data <= pb->data) {
            smaller = pa; pa = pa->next;
        } else {
            smaller = pb; pb = pb->next;
        }
        /* 头插法 */
        smaller->next = hc;
        hc = smaller;
    }
    /* 处理剩余段 */
    Node *rest = pa ? pa : pb;
    while (rest) {
        Node *p = rest;
        rest = rest->next;
        p->next = hc;
        hc = p;
    }
    return hc;
}

/* 打印链表 */
void printList(Node *head) {
    for (Node *p = head; p; p = p->next) {
        printf("%d", p->data);
        if (p->next) printf(" ");
    }
    //printf("\n");
}   

/* 释放链表 */
void freeList(Node *head) {
    while (head) {
        Node *p = head;
        head = head->next;
        free(p);
    }
}

int main() {
    int n, m;
    scanf("%d", &n);
    Node *ha = createList(n);
    scanf("%d", &m);
    Node *hb = createList(m);

    Node *hc = mergeReverse(ha, hb);
    printList(hc);

    freeList(hc);   /* 所有结点已挂在 hc 上，统一释放即可 */
    return 0;
}