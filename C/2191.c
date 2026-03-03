#include <stdio.h>
#include <string.h>
#include <stdlib.h>




typedef struct Node
{
    char name[10];
    int score;
    struct Node *next;
}Node;   

void swap(Node *p1,Node *p2)
{
    //µ÷»»name
    char str1[10];
    strcpy(str1,p1->name);
    strcpy(p1->name,p2->name);
    strcpy(p2->name,str1);
    //µ÷»»score
    int temp=p1->score;
    p1->score = p2->score;
    p2->score = temp;
}

void sort(Node *head)
{   
    int flag=0;
    do
    {   Node *p=head;
        flag=0;
        while(p!=NULL && p->next != NULL)
        { 
            if(p->score>(p->next)->score)
            {
                swap(p,p->next);
                flag=1;
            }
            p=p->next;
        }

    }
    while(flag==1);
}
int main()
{   int count =0;
    Node *p=NULL;
        Node *q=NULL;
        Node *head=NULL;
    while(1)
    {   
        p=(Node *)malloc(sizeof(Node));
        scanf("%s",p->name);
        count++;
        if(strcmp(p->name,"#")==0) 
        {
            free(p);
            break;
        }
        scanf("%d",&p->score);
        p->next=NULL;
        if(head==NULL)
        {
            q=p;
            head=q;
        }
        else
        {
            q->next=p;
            q=p;
        }
        
     }

     int m=0;
    sort(head);
    Node* k=head;
     while(k!=NULL)
     {  m++;
        printf("%s %d\n",k->name,k->score);
        k=k->next;
     }
}