#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


struct node{
	int data;
	struct node * next;
};

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
		printf("Enter the element :");
		scanf("%d",&data);
		start=insert(start,data);
		printf("Press 1 to terminate:");
		scanf("%d",&i);
	}
	return start;
}

struct node * alternateList(struct node * start,struct node * alter){
	struct node* ptr=start;
	while(ptr!=NULL){
		if(ptr->next==NULL){
			alter=insert(alter,ptr->data);
			break;
		}
		alter=insert(alter,ptr->data);
		ptr=ptr->next->next;
	}
	return alter;
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
	struct node * h1,*alter;
	h1=alter=NULL;
	h1=create(h1);
	print(h1);
	alter=alternateList(h1,alter);
	print(alter);
	return 0;
}