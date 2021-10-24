#include <stdio.h>
#include < stdlib.h >
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#define MAX_STACK_SIZE 100
#pragma warning(disable:4996) 

typedef struct stack {
    int data[MAX_STACK_SIZE];
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



void push(Stack* s, int item) {
    if (is_full(s)) {
        printf("Stack is full\n");
        exit(1);
    }
    (s->top)++;
    s->data[s->top] = item;
    //printf("item %d is pushed\n", s->data[s->top]);

    return;
}

int pop(Stack* s) {

    int temp;
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

int Palindrome(char in[]) {
    Stack s;
    char ch, open_ch;
    int i;
    int n = strlen(in);
    init_stack(&s);
    // �빮�� �ҹ��� ��ȯ.
    for (i = 0; i<n; i++) {
        if (in[i]<='Z'&&in[i]>='A'){
            in[i] += 32;
            //printf("%c", in[i]);
        }
    }
    //printf("%s\n", in);
   
    

    //�ҹ��ڴ� ���ÿ� �״´�.
    for (i = 0; i < n; i++) {
        ch = in[i];
        if (ch <= 'z' && ch>='a') {
            push(&s, ch);
        } 
    }
    // ���þȿ��ִ� ���� �Űܳ��´�
    char op[100];
    for (i = 0; i <=s.top; i++) {
        op[i] = s.data[i];

    }
    //pop�ؼ� ���°��� ���Ѵ�
    for (i = 0; i <= s.top; i++) {
        open_ch = pop(&s);
        if (open_ch != op[i]) 
            return 0;       
    }

   
    return 1;
}


int main() {

   
    char p[100];
    printf("�Է��ϼ���:");
    scanf("%[^\n]s", &p);// �������� �Է¹ޱ�
  
    if (Palindrome(p) == 1)
        printf(" Palindrome!");
    else
        printf("NO");
    return 0;

}