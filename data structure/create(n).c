#include <stdio.h>
#include <stdlib.h>

struct Node {
    int x;
    struct Node* next;
};

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