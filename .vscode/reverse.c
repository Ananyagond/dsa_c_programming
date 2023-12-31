#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head=NULL;
int create();
int reverse();
int display();

int create(struct node *head,int value){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=head;
    head=newnode;
}
int reverse(){
    struct node *prevnode=NULL,*currentnode,*nextnode;
    currentnode=nextnode=head;
    while(nextnode!=NULL){
        nextnode=nextnode->next;
        currentnode->next=prevnode;
        prevnode=currentnode;
        currentnode=nextnode;
    }
    head=prevnode;
}
int display(struct node *head){
    struct node *ptr=head;
    while(ptr!=NULL){
        printf("%d",ptr->data);
        ptr=ptr->next;
    }
}
int main(){
    struct node *head=NULL;
    int value;
    printf("ENter the data:");
    scanf("%d",&value);
    printf("LINKED LIST before reversing:\n");
    create(head,value);
    printf("LINKED LIST AFTER reversing:\n");
    reverse();
    display(head);
}
