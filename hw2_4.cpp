#include <stdio.h>
#include < stdlib.h >
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#define MAX_STACK_SIZE 100
#pragma warning(disable:4996) 

typedef struct stack {
    double data[MAX_STACK_SIZE];
    int top;
}Stack;

void init_stack(Stack* s) {
    (s->top) = -1;
    return;
}

int is_full(Stack* s) {
    if (s->top == MAX_STACK_SIZE - 1)
        return 1;
    else
        return 0;
}

int is_empty(Stack* s) {
    if (s->top == -1)
        return 1;
    else
        return 0;
}



void push(Stack* s, double item) {
    if (is_full(s)) {
        printf("Stack is full\n");
        exit(1);
    }
    (s->top)++;
    s->data[s->top] = item;
    //printf("item %d is pushed\n", s->data[s->top]);

    return;
}

double pop(Stack* s) {

    double temp;
    if (is_empty(s)) {
        printf("Stack is empty\n");
        exit(1);
    }

    else {
        temp = s->data[s->top];
        (s->top)--;
        //printf("item %d is popped\n", temp);
        return temp;

    }
}
double perform(char exp,double op1, double op2) {
    Stack s;
    init_stack(&s);
    
    switch (exp) {
    case '+':push(&s, op1 + op2); break;
    case '-':push(&s, op1 - op2); break;
    case '*':push(&s, op1 * op2); break;
    case '/':push(&s, op1 / op2); break;
    }
    return pop(&s);
}

double Res(char exp[]) {
    Stack s;
    init_stack(&s);
    char ch;
    int length = strlen(exp);//exp길이
    double op1, op2, value = 0;
    
    double res;
    for (int i = 0; i <=length-1 ; i++) {
       // printf("%d\n", exp[i]);
        ch = exp[i];

        if (exp[i]!= '+' && exp[i] != '-' && exp[i] != '*' && exp[i] != '/') {
            value = ch - '0';//아스키 코드값으로 받았기 때문에
            
            //printf("%d\n", value);
            push(&s, value);//아스키 코드값으로 받았기 때문에
        }
        
        else {
            ch = exp[i];
            op2 = pop(&s);
            op1 = pop(&s);
            res = perform(ch, op1, op2);
            push(&s, res);
   
        }
        
        
    }
    return pop(&s);
}
int main() {
    
    char p[100];
    //float result;
    double result;
    printf("후위 표기 수식을 입력하세요:");
    scanf("%s", &p);
    
    result = Res(p);
    printf("계산값:%.2f", result);
    return 0;

}