#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
typedef struct Node Node;
Node* create(int *count)
    {
        Node* head = NULL;
        Node* pnew = NULL;
        Node* end = NULL;
        while(1)
        {

            pnew = (Node*)malloc(sizeof(Node));
            scanf("%d", &pnew->data);
            pnew->next = NULL;
            if(pnew->data == -1)
            {
                free(pnew);
                break;
            }
            (*count)++;
            if(head == NULL)
            {
                head = pnew;
                end = pnew;
            }
            else
            {
                end->next = pnew;
                end = pnew;
            }
        }
        return head;
    }