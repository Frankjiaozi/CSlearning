#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int val;
    int pos;
    struct Node* next;
};
typedef struct Node Node;


Node* insert(Node* head)
{
    int pos;
    int val;
    scanf("%d %d", &pos, &val);
    Node* pnew = (Node*)malloc(sizeof(Node));
    pnew->val = val;
    pnew->pos = pos;
    pnew->next = NULL;

    // 插在头部
    if (pos == 1 || head == NULL) {
        pnew->next = head;
        return pnew;   // 新节点变成新 head
    }

    // 找到第 pos-1 个节点 pre
    Node* pre = head;
    for (int i = 1; i < pos-1; i++) {
        if (pre->next == NULL) break; // 超出长度就插最后
        pre = pre->next;
    }

    // 插在 pre 后面
    pnew->next = pre->next;
    pre->next = pnew;

    return head;
}

Node* delete(Node* head)//1 2 3 4  5 6
{
    int pos;
    scanf("%d", &pos);
    Node* p = head;
    while(p->pos!=pos)
    {
        p = p->next;
    }
    Node* pre = head;
    while(pre->next!=p)
    {
        pre = pre->next;
    }
    if(pos==1)
    {
        head = head->next;
        free(p);
        p = NULL;

    }
    else
    {
    pre->next = p->next;
        free(p);
        p = NULL;
    }
    return head;
}

void print(Node* head)
{
    Node* p = head;
    while(p!=NULL)
    {
        printf("%d",p->val);
        if(p->next!=NULL)
        {
            printf(" ");
        }
        p = p->next;
    }
}

void clear(Node* head)
{
    Node* p=head;
    while(p!=NULL)
    {
        Node* q = p;
        p = p->next;
        free(q);
        q = NULL;
    }
}

void getelem(Node* head)
{
    int pos;
    scanf("%d", &pos);
            int flag=0;
            Node* p = head;
            while(p!=NULL)
            {
                if(p->pos==pos)
                {
                    flag=1;
                    printf("%d", p->val);
                    break;
                }
                p = p->next;
            }
            if(flag==0)
            {
                printf("Not Found");
            }

    printf("\n");
}


int main()
{
    Node* head = NULL;
    while(1)
    {
        char cmd[10];
        scanf("%s", cmd);
        if(strcmp(cmd,"insert")==0)
        {
            head = insert(head);
            printf("\n");
        }

        if(strcmp(cmd,"exit")==0)
        {
            break;
        }

        if(strcmp(cmd,"clear")==0)
        {
            printf("\n");
            clear(head);
        }
        //print(head);
        if(strcmp(cmd,"getelem")==0)
        {
            printf("\n");
            getelem(head);
        }
        if(strcmp(cmd,"delete")==0)
        {
            printf("\n");
            head = delete(head);
        }
        if(strcmp(cmd,"print")==0)
        {
            print(head);
        }
    
    }
}