#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
} ;
int main(){
    struct node *head = NULL,*ptr=NULL,*f;
    int num  , list , count=0,i;
    printf("Enter the number of elements in the linked list:");
    scanf("%d",&num);
    printf("Enter the  elements in the linked list:\n");
    for(i=0;i<num;i++)
    {
        struct node *p;
        p=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&p->data);
        p->next=ptr;
        ptr=p;
    }
    printf("\nEnter the element which is to be find:");
    scanf("%d",&list);
    f=ptr;
    while(f!=NULL)
    {
        if(f->data==list)
        {
            count ++;
        }
        f=f->next;
    }
    printf("%d ouccurence of number in the list is: %d\n",list,count);
}
    