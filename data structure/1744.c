#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int value;
    struct Node *next;
};

typedef struct Node Node;


Node* create()
{
    int temp;
    Node* head = NULL;
    Node* end = NULL;
    Node* pnew = NULL;
while(scanf("%d",&temp)!=EOF && temp!=-1)
{
    pnew = (Node*)malloc(sizeof(Node));
    pnew->value = temp;
    pnew->next = NULL;
    
    if(head == NULL)
    {
        head = pnew;
        end  = pnew;
    }
    else
    {
        end ->next = pnew;
        end = pnew;
    }
}
    return head;
}

int isinlist(Node* head,int x)
{
    Node* p = head;
    while(p!=NULL)
    {
        if(p->value == x)
        {
            return 1;
            break;
        }
        p = p->next;
    }
     return 0;

}



void print(Node* head)
{
    Node* p = head;
    while(p!=NULL)
    {
        printf("%d ",p->value);
        p = p->next;
    }
}

void add(Node** head,int x)
{   
    Node* p = *head;
    if(p == NULL){
        Node* padd = (Node*)malloc(sizeof(Node));
        padd->value = x;
        padd->next = NULL;
        *head = padd;    
    }
    else{
        while(p->next!=NULL)
    {
        p = p->next;
    }
    Node* padd = (Node*)malloc(sizeof(Node));
    padd->value = x;
    padd->next = NULL;
    p->next = padd;
    }
    
}
void sort(Node* head,int n)
    {
        Node* p = head;
        for(int i = 0; i < n - 1; i++)
        {
            p = head;
            while(p->next != NULL)
            {
                if(p->value > p->next->value)
                {
                    swap(p);
                }
                p = p->next;
            }
        }
    }


int count(Node* head)
{
    int count = 0;
    Node* p = head;
    while(p!=NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}
int main()
{
    Node* headA = create();
    Node* headB = create();
    Node* headC  = NULL;
    Node* pa = headA;
    Node* pb = headB;
    while(pa!=NULL && pb!=NULL)
    {
        if(pa->value > pb->value)
        {   if(isinlist(headA,pb->value)==1 && isinlist(headB,pb->value)==0 && isinlist(headC,pb->value)==0)
            {
                add(&headC,pb->value);
                pb = pb->next;
            }
            else{
                pb = pb->next;
            }
            
        }
        else{
            if(isinlist(headA,pa->value)==1 && isinlist(headB,pa->value)==0 && isinlist(headC,pa->value)==0)
            {
                add(&headC,pa->value);
                pa = pa->next;
            }
            else{
                pa = pa->next;
            }

        }
    }
    while(pa!=NULL)
    {   
        if(isinlist(headA,pa->value)==1 && isinlist(headB,pa->value)==0 && isinlist(headC,pa->value)==0)
        {
             add(&headC,pa->value);
            pa = pa->next;
        }
        else
        {
             pa = pa->next;
        }
       
    }
    while(pb!=NULL)
    {   
        if(isinlist(headA,pb->value)==1 && isinlist(headB,pb->value)==0 && isinlist(headC,pb->value)==0)
        {
             add(&headC,pb->value);
            pb = pb->next;
        }
        else
        {
             pb = pb->next;
        }
       
        
    }
    print(headC);
    printf("\n");
    printf("%d",count(headC));



}