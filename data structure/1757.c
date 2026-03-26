    #include <stdio.h>
        #include <stdio.h>
        #include <stdlib.h>

        struct Node {
            int x;
            int index;
            struct Node* next;
        };

        struct Node* create(int n) {
            struct Node* head = NULL;
            struct Node* pnew = NULL;
            struct Node* end = NULL;
            
            for (int i = 0; i < n; i++) {
                pnew = (struct Node*)malloc(sizeof(struct Node));
                scanf("%d", &pnew->x);
                pnew->index = i+1;
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
    typedef struct Node Node;

    void print(Node *head)
    {
        while(head!=NULL)
        {
            printf("%d ",head->x);
            head = head->next;
        }
        printf("\n");
    }
    int main()
    {
        int n;
        scanf("%d", &n);
        struct Node* head = create(n);
        Node *headA = head;
        Node *headB = head->next;
        Node *p = head;
        Node *endA = NULL;
        Node *endB = NULL;
        while(p!=NULL)
        {
            if(p->index ==1)
            {
                headA = p;
                endA = p;
            }
            else if(p->index ==2)
            {
                headB = p;
                endB = p;
            }
            else if(p->index %2==0)
            {
                endB->next = p;
                endB = p;
            }
            else if(p->index %2!=0)
            {
                endA->next = p;
                endA = p;
            }

            p=p->next;
        }
        endA->next = NULL;
        endB->next = NULL;
        print(headA);
        print(headB);
    }
