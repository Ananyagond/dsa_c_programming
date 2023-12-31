#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
 } ;
 struct node * insert(struct node* start,int data){
	struct node * temp, * ptr;
	ptr=NULL;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->next=NULL;
	if(start==NULL){
		start=temp;
	}
	else{
		ptr=start;
		while(ptr->next!=NULL){
			ptr=ptr->next;
		}
		ptr->next=temp;
	}
	return start;	
}
struct node * create(struct node * start){
	int i=0,data;
	while(i!=1){
		printf("Enter the elemnet :");
		scanf("%d",&data);
		start=insert(start,data);
		printf("Press 1 to terminate:");
		scanf("%d",&i);
	}
	return start;
}

struct node *reverse(struct node *start)
{
    struct node *rev;
    if (start == NULL || start->next == NULL)
    {
        return start;
    }

    rev=reverse(start->next);
    start->next->next=start;
    start->next=NULL;
    return rev;
}


void print(struct node* start){
	struct node * ptr;
	ptr=start;
	while(ptr!=NULL){
		printf("%d->",ptr->data);
		ptr=ptr->next;
	}
	printf("NULL\n");
}

int main(){
	struct node * h1,*rev;
	h1=NULL;
	rev=NULL;
	h1=create(h1);
	print(h1);
	printf("\nReverse linked list is\n");
	rev=reverse(h1);
	print(rev);
	return 0;
}
 
 