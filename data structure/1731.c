#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Node {
    int x;
    struct Node* next;
    struct Node* back;
};

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

typedef struct Node Node;

void insert(Node* head)
{
    Node* newnode = (Node*)malloc(sizeof(Node));//head->newnode->next
    scanf("%d", &newnode->x);
    head->next->back = newnode;
    newnode->next = head->next;
    head->next = newnode;
    newnode->back = head;
}

void swap(Node* p)
    {
        int temp = p->x;
        p->x = p->next->x;
        p->next->x = temp;
    }

    void sort(Node* head,int n)
    {
        Node* p = head;
        for(int i = 0; i < n - 1; i++)
        {
            p = head;
            while(p->next != NULL)
            {
                if(p->x > p->next->x)
                {
                    swap(p);
                }
                p = p->next;
            }
        }
    }
 int main()
 {
    int n;
    scanf("%d", &n);
    Node* head =create(n);
    //insert(head);
    sort(head,n);
     Node* p = head;
     for(int i = 0; i < n; i++)
     {
        printf("%d ", p->x);
        p = p->next;
     }



 }
