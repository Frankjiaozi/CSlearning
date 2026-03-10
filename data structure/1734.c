#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Node {
    int x;
    struct Node* next;
    struct Node* back;
};
typedef struct Node Node;

struct Node* create(int n) {
    struct Node* head = NULL;
    struct Node* pnew = NULL;
    struct Node* end = NULL;
    for (int i = 0; i < n; i++) {
        pnew = (struct Node*)malloc(sizeof(struct Node));//p1 - p2 - p3 - ... - pn
        scanf("%d", &pnew->x);
        pnew->next = NULL;
        pnew->back = NULL;
        
        if (head == NULL) {
            head = pnew;
            end = pnew;
        } else 
        {
            end->next = pnew;
            pnew->back = end;
            end = pnew;
        }
    }
    return head;
}


 int main()
 {
    int n;
    scanf("%d", &n);
    Node* head =create(n);
    //insert(head);
    int x;
    scanf("%d", &x);
     Node* p = head;
     for(int i = 0; i < n; i++)
     {
        if(p->x !=x)
        {
            printf("%d ", p->x);
        }
        p = p->next;
     }



 }
