#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char name[10];
    int score;
    struct Node *next;
}Node;

float avr(Node* head)
{   float sum=0.0;
    int count=0;
    Node* p=head;
    while(p!=NULL)
    {
        sum+=(float)p->score;
        p=p->next;
        count++;
    }
    float avr=sum/count;
    return avr;
}

void find(Node *head)
{   Node* temp=head;
    int max = head->score;
    Node * p=head;
    while(p!=NULL)
    {
        if(max<p->score) 
        {
            max=p->score;
            temp=p;
        }
        p=p->next;
    }
    printf("%s %d\n",temp->name,max);
}

int main()
{   
    int m;//m代表班级个数
    scanf("%d",&m);
    Node* arr[m];//建立存放头指针的数组
    for(int i=0;i<m;i++)//i代表第i个班级
    {   int n;
        scanf("%d",&n);
         Node* p=NULL;
            Node* q=NULL;
        for(int j=0;j<n;j++)
        {
           
            p=(Node*)malloc(sizeof(Node));
            scanf("%s %d",p->name,&p->score);
            p->next=NULL;
            if(j==0)
            {
                arr[i]=p;
                q=p;
            }
            else 
            {
                q->next=p;
                q=p;
            }

        }
        printf("%d ",i+1);
        printf("%.2lf ",avr(arr[i]));
        find(arr[i]);

    }
}