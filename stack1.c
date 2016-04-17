#include <stdio.h>
#include<stdlib.h>
#define MAX 10
int stack_arr[MAX];
int top=-1;
void push(int item);
int pop();
int peek();
int isEmpty();
int isFull();
void display();
main()
{
	int choice,item;
	while(1){
		printf("1.Push\n");
		printf("2.pop\n");
		printf("3.display top elements\n");
		printf("4.display all stack elements\n");
		printf("5.exit\n");
		printf("enter ur choice\n");
		scanf("%d\n", &choice);
		switch(choice){
			case 1:
				printf("enter the item to be pushed\n");
				scanf("%d", &item);
				push(item);
				break;
			case 2:
				item=pop();
				printf("popped item is %d\n",item);
				break;
			case 3:
				printf("top element is %d\n",peek());
				break;
			case 4:
				display();
				break;
			case 5:
				exit(1);
			default:
				printf("wrong choice\n");
		}
	}
}
void push(int item){
	if (isFull()){
		printf("stack overflow\n");
		return;
	}
	top=top+1;
	stack_arr[top]=item;
}
int pop(){
	int item;
	if (isEmpty()){
		printf("stack underflow\n");
		exit(1);
	}
	item=stack_arr[top];
	top=top-1;
	return item;
}
int peek(){
	if(isEmpty()){
		printf("stack is empty");
		exit(1);
	}
	return stack_arr[top];
}
int isEmpty(){
	if(top==-1){
		return 1;
	}
	else
		return 0;
}
int isFull(){
	if(top==MAX-1){
		return 1;
	}
	else
		return 0;
}
void display(){
	int i;
	if(isEmpty()){
		printf("stack is empty\n");
		exit(1);
	}
	else{
		for(i = top; i >= 0; i--){
			printf("%d ",stack_arr[i]);
		}
		printf("\n");
	}
}
