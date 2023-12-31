#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define max 100
int stack[max];
int top=-1;
int push (int data){
    if(top==max-1){
        printf("overflow stack\n");
        return;
    }
    top++;
    stack[top]=data;
}
int pop(int data){
    if(top==-1){
        printf("underflow stack\n");
        return;
    }
    data=stack[top];
    top=top-1;
    return data;
}

void diaplay(){
    int i;
    if(top==-1){
        printf("underflow stack");
        return;
    }
    printf("stack elements are:\n");
    for(i=top;i>=0;i--)
    printf("%d",stack[i]);
    printf("\n");
}
int main(){
    int choice,data;
    while (1)
    {
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Print the top elements\n");
        printf("4.Print all the elements of the stack\n");
        printf("5.Quit\n");
        printf("Please enter your choice :");
        scanf("%d",&choice);
        switch(choice){
            case 1:
               printf("Enter the elements to be pushed:");
               scanf("%d",&data);
               push(data);
               break;
            case 2:
               pop(data);
               printf("Deleted element is %d \n",data);
               break;  
            case 4:
                print(" ");
                break;
            case 5:
                exit(1);
            default:
                 printf("Wrong choice\n");

        }
    }
    return 0;
    
}