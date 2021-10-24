#include <stdio.h>
#include < stdlib.h >
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#define MAX_STACK_SIZE 5
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

int check( char in[]) {
    Stack s;
    char ch, open_ch;
    int i;
    int n = strlen(in);
    
    init_stack(&s);
    for (i = 0; i < n; i++) {
        ch = in[i];
        switch (ch) {
        case'(':
        case'[':
        case'{':
            push(&s, ch);
            break;
        case')':
        case']':
        case'}':
            if (is_empty(&s))//비어있는데 닫히면 false
                return 0;
            else {
                open_ch = pop(&s);


                //같은짝인지 검사
                if ((open_ch == '(' && ch != ')') ||
                    (open_ch == '[' && ch != ']') ||
                    (open_ch == '{' && ch != '}')
                    )
                    return 0;
            }
            
            
            break;
        }
     }
    if (!is_empty(&s))
          return 0;
    return 1; 
}


int main() {


    char p[100];
    printf("수식을 입력하세요:");
    scanf("%s", &p);
    
  
    if (check(p) == 1)
        printf("YES");
    else
        printf("NO");
    return 0;

}