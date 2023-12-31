#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
int linkedlisttraversal(struct node *ptr){
    while(ptr != NULL)
    {
        printf("element:%d\n",ptr->data);
        ptr=ptr->next;
    }
}
struct node * insertatend(struct node *head,int data){
    struct node *ptr =(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    struct node *p = head;
    while(p->next!=NULL){
        p = p->next;
    }
    p->next=ptr;
    ptr->next = NULL;
    return head;
}
int main() {
    struct node *head;
     struct node *second;
     struct node *third;  
     struct node *fourth;    
     head = (struct node*)malloc(sizeof(struct node));
     second = (struct node*)malloc(sizeof(struct node));
     third = (struct node*)malloc(sizeof(struct node));
     fourth = (struct node*)malloc(sizeof(struct node));
     head->data=7;
     head->next=second;
     second->data=11;
     second->next=third;
     third->data=41;
     third->next=fourth;
     fourth->data=66;
     fourth->next=NULL;
     printf("linked list before insertion\n");
     linkedlisttraversal(head);
     printf("linked list after insertion\n");
    head = insertatend(head,56);
    linkedlisttraversal(head);
     return 0;
}