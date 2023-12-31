#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
int insert(struct node *head,int value)
{
    struct node *newnode;
    newnode= (struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=head;
    head=newnode;
    return 0;
}

int display(struct node *head){
    struct node *ptr=head;
    while(ptr!=NULL){
        printf("%d",ptr->data);
        ptr=ptr->next;
    } 
    return 0;
}
int main(){
    struct node *head=NULL;
    int value;
    printf("Enter the value:");
    scanf("%d",&value);
    insert(head,value);
    display(head);
    return 0;
}