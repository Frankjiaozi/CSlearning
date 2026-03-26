#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    int index;  
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
            pnew->index = ++(*count);
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
        while(p!=NULL)
        {
            printf("%d",p->data);
            if(p->next!=NULL) printf(" ");
            p=p->next;
        }
        //printf("\n");
    }
int main()
{
int i;
int len;
int j;
int countA = 0;
int countB = 0; 
scanf("i=%d,len=%d,j=%d", &i, &len, &j);
Node* headA = create(&countA);
Node* headB = create(&countB);
Node* p = headA;
Node* start = NULL;
Node* end = NULL;
int t =0;
if(i!=1)
{
    while(p->next!=NULL)//1->2->3->4->5->6->7->8->9->10->11->12->13->14->15
{
    if(p->next->index == i)
    {
         start = p;
         break;
    }
    p=p->next;
}
p=start;
t =0;
while(t<=len)
    {
        t++;
        p=p->next;
    }
    end = p;
//删除start到end之间的节点
start->next = end;
}

else
{
    t=0;
    while(t<len)
    {
        t++;
        p=p->next;
    }
    headA = p;
}

p=headB;


Node* preend = NULL;
while(p->next!=NULL)
{
    if(p->next->index == j)
    {
        preend = p;
        break;
    }
    p=p->next;
}
end = preend->next;
p=headA;
while(p->next!=NULL)
{
    p=p->next;
}
Node* endA = p;

preend->next = headA;
endA->next = end;
print(headB);





}