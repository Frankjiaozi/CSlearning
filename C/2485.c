#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Node
{
    int num;
    char name[100];
    int score;
    struct Node* next;
}Node;

Node* create(void)
{
Node* p=NULL;
Node* q=NULL;
Node* head = NULL;
while(1)
{
    p=(Node*)malloc(sizeof(Node));
    scanf("%d",&p->num);
    if(p->num == 0)
    {
        free(p);
        break;
    }
    scanf("%s",p->name);
    scanf("%d",&p->score);
    p->next=NULL;
    if(head== NULL)
    {
        head=p;
        q=p;
    }
    else
    {
        q->next = p;
        q=p;
    }
}
return head;
}

int  add(Node *head,int num,char name[],int score)
{
    Node * p=head;
    Node* last=NULL;
    while(p!=NULL)
    {
        if(p->num == num)
        {
            printf("%s","Record exists!");
            return 0;
        }
        if(p->next == NULL)
        {
            last=p;
        }
        p=p->next;
    }
    Node* neew=NULL;
    neew = (Node*)malloc(sizeof(Node));
    strcpy(neew->name,name);
    neew->num=num;
    neew->score=score;
    neew->next=NULL;
    last->next=neew;
    return 1;
}

void print(Node*head)
{
    Node* p=head;
    while(p!=NULL)
    {
        printf("%d %s %d\n",p->num,p->name,p->score);
        p=p->next;
    }
}

void sort(Node* head)
{   
   int flag=0;
    do
    {
        flag=0;
        Node *p=head;
         while(p!=NULL && p->next !=NULL)
         {
            if(p->num > p->next->num)
            {
              int temp_num = p->num;
                p->num = p->next->num;
                p->next->num = temp_num;

                // 2. 交换name（字符串用strcpy）
                char temp_name[100];
                strcpy(temp_name, p->name);
                strcpy(p->name, p->next->name);
                strcpy(p->next->name, temp_name);

                // 3. 交换score
                int temp_score = p->score;
                p->score = p->next->score;
                p->next->score = temp_score;
                flag=1;
                
            }
           p=p->next;
         }
    
    } while (flag==1);
    
}

int main()
{
    Node* head = create();
    //输入学生信息
    int num;
    char name[100];
    int score;
    scanf("%d %s %d",&num,name,&score);
    add(head,num,name,score);
    sort(head);
    print(head);
}