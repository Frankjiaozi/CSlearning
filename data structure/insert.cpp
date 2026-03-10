

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int x;
    struct Node* next;
    struct Node* back;
};


void insert(Node* head)
{
    Node* newnode = (Node*)malloc(sizeof(Node));//head->newnode->next
    scanf("%d", &newnode->x);
    head->next->back = newnode;
    newnode->next = head->next;
    head->next = newnode;
    newnode->back = head;
}