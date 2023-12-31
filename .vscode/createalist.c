#include<stdio.h>
#include<stdlib.h>
struct node {
    int data ;
    struct node *next;
} ;
int main() {
    struct node *p,*temp;
    int n,i,element;
    printf("Enter number of nodes : ");
    scanf("%d",&n);
    printf("Enter node number: ");
    scanf("%d",&element);
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=element;
    temp->next=NULL;
    p=temp;
    for(i=1;i<=n;i++)  {
        printf("enter node number %d");
        scanf("%d",&element);
        temp=(struct node*)malloc(sizeof(struct node));
        temp->data=element;
        temp->next=NULL;
        p->next=temp;
        p=p->next;
    }
}