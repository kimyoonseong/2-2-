#include <stdio.h>

#define MAX_STACK_SIZE 5

typedef struct stack{
  	int data[MAX_STACK_SIZE];
  	int top;
}Stack;

void init_stack(Stack *s){
  	(s->top)=-1;
  		return;
}

int is_full(Stack *s){
  	if(s->top==MAX_STACK_SIZE-1)
    	return 1;
  	else 
    	return 0;

}
int is_empty(Stack *s){
  	if(s->top==-1)
    	return 1;
  	else 
    	return 0;
}

 

void push(Stack *s,int item){
  	if(is_full(s)){
    	printf("Stack is full\n");
    	//exit(1);
 	}
  	(s->top)++;
  	s->data[s->top]=item;
  	printf("item %d is pushed\n", s->data[s->top]);
  
  return;

}

int pop(Stack *s){
 	int temp;
 	if(is_empty(s)){
    	printf("Stack is empty\n");
    	//exit(1);
 	}

 	else{
  		temp=s->data[s->top];
  		(s->top)--;
  		printf("item %d is popped\n",temp);
  	return temp;
	}
}

 

int main() {

  	Stack *s=NULL;

  	s=(Stack *)malloc(sizeof(Stack));

  

  	if(s==NULL){

    	printf("Dynamic memory allocation failed\n");
   		exit(1);
  	}

  	init_stack(s);

  

  	push(s,1);
  	push(s,2);
  	push(s,3);
  	push(s,4);
  	push(s,5);
  	pop(s);
  	pop(s);
  	push(s,100);
	
  	printf("the current value of top is %d\n", s->top);

  	printf("the num of items in the stack: %d\n",(s->top)+1);

  
  return 0;

}




