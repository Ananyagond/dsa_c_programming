#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
int main(){
struct node *head=NULL;struct node *newnode;struct node *temp;
int choice,count=0;
while(choice){
    newnode=(struct node*)malloc(sizeof(struct node));
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d",newnode->data);
    newnode->next=NULL;
    if(head==NULL){
        head=temp=newnode;
    }
    else{
        temp->next=newnode;
        temp=newnode;
    }
    printf("press 0 ,1 to continue");
    scanf("%d",&choice);
}
temp=head;
while(temp!=NULL){
    printf("%d",temp->data);
    temp=temp->next;
    count++;
}
printf("%d",count);
}