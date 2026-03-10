    #include <stdio.h>
    #include <stdlib.h>
    int count = 0;
    struct Node
    {
        int data;
        struct Node* next;
    };
    typedef struct Node Node;
    void swap(Node* p)
    {
        int temp = p->data;
        p->data = p->next->data;
        p->next->data = temp;
    }

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

    void print(Node* head)
    {
        Node* p = head;
        if (p == NULL) return;
        // 第一个节点直接输出，后续节点前加空格，避免末尾多余空格
        printf("%d", p->data);
        p = p->next;
        while (p != NULL) {
            printf(" %d", p->data);
            p = p->next;
        } 
        //printf("\n"); 
    }
    void sort(Node* head)
    {
        Node* p = head;
        for(int i = 0; i < count - 1; i++)
        {
            p = head;
            while(p->next != NULL)
            {
                if(p->data > p->next->data)
                {
                    swap(p);
                }
                p = p->next;
            }
        }
    }
    int main()
    {
        Node* head = create(&count);
        sort(head);
        print(head);
        return 0;
    }