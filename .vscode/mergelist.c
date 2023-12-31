#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
} ;
int sort(struct node *c){
    struct node *original,*num=NULL;
    int a;
    original = c;
    while(original!=NULL){
        num=original->next;
        while(num!=NULL){
            if(original->data > num->data)
            {
                a = original->data;
                original ->data = num->data;
                num->data=a;
            }
            num = num->next;
        }
        original = original->next;
    }
} 
struct node *merge(struct node *p,struct node *q){
    if(p==NULL)
    return q;
    if(q==NULL)
    return p;
    struct node *m=NULL;
    if(p->data <= q->data){
        m=p;
        m->next = merge(p->next,q);
    }
    else{
        m=q;
        m->next = merge(p,q->next);
    }
    return m;
}
int main() {
    int b,k;
    struct node *p,*q,*a;
    p=(struct node*)malloc(sizeof(struct node));
    q=(struct node*)malloc(sizeof(struct node));
    printf("Enter the size of the list:" );
    scanf("%d",&b);
    printf("Enter the elments in the first list:\n");
    for(k=0;k<b;k++){
        struct node *s1;
        s1=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&s1->data);
        p=s1;
    }
    printf("Enter the elments in the second list:\n");
    for(k=0;k<b;k++){
        struct node *s2;
        s2=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&s2->data);
        p=s2;
    }
    a=merge(p,q);
    printf("LIST MERGED:\n");
    sort(a);
    printf("LIST MERGED:\n");
    printf("Merged and Sorted linked list :\n");
    struct node *f=NULL;
    f=a;
    while(f!=NULL)
    {
        printf("%d",f->data);
        f=f->next;
    }
}