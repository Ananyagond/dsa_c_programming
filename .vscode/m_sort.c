#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node * next;
};

struct node *insert(struct node* start,int data){
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
		printf("Enter data:");
		scanf("%d",&data);
		start=insert(start,data);
		printf("Press 1 to terminate:");
		scanf("%d",&i);
	}
	return start;
}

struct node * merge(struct node*h1,struct node*h2,struct node*h3){
	struct node*p1=h1,*p2=h2;
	while(p1!=NULL && p2!=NULL){
		if(p1->data<p2->data){
			h3=insert(h3,p1->data);
			p1=p1->next;
		}
		else{
			h3=insert(h3,p2->data);
			p2=p2->next;
		}
	}
	while(p1!=NULL){
		h3=insert(h3,p1->data);
		p1=p1->next;
	}
	while(p2!=NULL){
		h3=insert(h3,p2->data);
		p2=p2->next;
	}
	return h3;
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
	struct node * h1,*h2,*h3;
	h1=h2=h3=NULL;
	h1=create(h1);
	print(h1);
	h2=create(h2);
	print(h2);
	printf("\nMerge List\n");
	h3=merge(h1,h2,h3);
	print(h3);
	return 0;
}