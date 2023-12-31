#include<stdio.h>
#include<stdlib.h>
struct node{
    int expo;
    float coeff;
    struct node *link; 
};
struct node *insert(struct node *head,float co,int ex){
    struct node *temp;struct node *newp;
    newp=(struct node*)malloc(sizeof(struct node));
    newp->coeff=co;
    newp->expo=ex;
    newp->link=NULL;
    if(head==NULL || ex > head->expo){
        newp->link=head;
        head=newp;
    }else{
        temp=head;
        while(temp->link != NULL && temp->link->expo > ex){
            temp=temp->link;
            newp->link=temp->link;
            temp->link=newp;
        }
    }
    return head;
}
struct node *create(struct node *head){
    int i,n,expo;
    float coeff;
    printf("Enter the number of terms: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the coefficient for term %d:",i+1);
        scanf("%d",&coeff);
        printf("Enter the exponent for term %d:",i+1);
        scanf("%d",expo);
        head=insert(head,coeff,expo);
    }
    return head;
}
void display(struct node *head){
    if(head == NULL){
        printf("No Polynomial");
    }
    else{
        struct node *temp=head;
        while(temp != NULL){
            printf("(%fx^%d)",temp->coeff,temp->expo);
            temp=temp->link;
            if(temp != NULL)
                printf("+");
            else{
                printf("\n");
            }
        }
    }
}
int main(){
    struct node *head=NULL;
    printf("Enter the polynomials\n");
    head=create(head);
    display(head);
    return 0;
}