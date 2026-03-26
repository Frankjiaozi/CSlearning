    #include <stdio.h>
    #include <stdlib.h>
    struct Node {
        int x;
        int index;
        struct Node* next;
    };
    typedef struct Node Node;
    Node* create(int n) {
        struct Node* head = NULL;
        struct Node* pnew = NULL;
        struct Node* end = NULL;
        
        for (int i = 0; i < n; i++) {
            pnew = (struct Node*)malloc(sizeof(struct Node));
            scanf("%d", &pnew->x);
            pnew->next = NULL;
            pnew->index = i+1;
            
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
    int main()
    {
        int n;
        scanf("%d", &n);
        struct Node* head = create(n);
        Node* pre = head;
        
        int flag=1;
        if(pre!=NULL)
        {   Node* cur = pre->next;
            while(cur != NULL) 
        {
            if(cur->x != (cur->index*cur->index)-pre->x)
            {
                flag=0;
                break;
            }
            pre =cur;
            cur = cur->next;
        }
        }
        else{
            flag=1;
        }
        
        if(flag)
        {
            printf("true");
        }
        else{
            printf("false");
        }
    }