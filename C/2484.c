#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int ID;
    char name[100];
    int score;
    struct Node* next;
}Node;

Node* create(void)
{
    Node* p=NULL;
    Node* q=NULL;
    Node* head=NULL;
    while(1)
    {
        p=(Node*)malloc(sizeof(Node));
        scanf("%d",&p->ID);
        if(p->ID == 0)
        {
            free(p);
            break;
        }
        scanf("%s %d",p->name,&p->score);
        p->next=NULL;
        if(head==NULL)
        {
            head=p;
            q=p;
        }
        else
        {
            q->next=p;
            q=p;
        }
    }
    return head;
}
//////////²éÕÒº¯Êý
int find(Node* head,int ID)  
{
Node *p = head;
int flag=0;
while(p!=NULL)
{
    if(p->ID==ID)
    {
        printf("%d %s %d\n",p->ID,p->name,p->score);
        flag=1;
    }
    if(flag==1) break;
    p=p->next;
}
return flag;
}





int main()
{
Node* head = create();
int ID;
scanf("%d",&ID);
find(head,ID);
}