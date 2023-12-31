#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void indexsearch(int arr[20],int n,int item){
	int element[20],index[20],g=3,ind=0,i=0,end,beg,flag=0;
	for(i=0;i<n;i=i+g){
		element[ind]=arr[i];
		index[ind]=i;
		ind++;
	}
	if(item<element[0]){
		printf("not present");
		exit(0);
	}
	else{
		for(i=1;i<=ind;i++){
			if(item<element[i]){
				
				beg=index[i-1];
				end=index[i];
				break;
			}
		}
	}
	
	for(i=beg;i<=end;i++){
		if(item==arr[i]){
			flag++;
			break;
		}
	}
	if(flag){
		printf("Element is present at index %d",i);
	}
	else{
		printf("Element is not present");
	}
	
}

int main(){
	int arr[16]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	indexsearch(arr,15,9);
	return 0;
}

