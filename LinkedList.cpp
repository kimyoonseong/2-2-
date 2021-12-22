#define _CRT_SECURE_NO_WARNINGS
#define MAX_STACK_SIZE 5
#include<stdio.h>
#include<stdlib.h>
#define TRUE 1;
#define FALSE 0;
typedef struct node {
    int data;
    struct node* link;
}Node;

Node* create_node(int value) {

    Node* temp = NULL;
    temp = (Node*)malloc(sizeof(Node));
    if (temp == NULL) {
        printf("Memory allocation failed!!\n");
        exit(1);
    }

    temp->data = value;
    temp->link = NULL;

    return temp;
}


Node* insert_first(Node* head, int item) {

    Node* temp = NULL;

    temp = create_node(item);
    if (temp != NULL) {
        // Make temp node as the first node
        // The next node of the temp is the previously first node
        temp->link = head;

        // Make head pointer point to temp node
        head = temp;
    }
    return head;
}
//Make a new node and insert it after pre node

//value 값을 노드로 만든후 .pre 포인터가 가르키는 노드 담에 삽입
/*
Node* insert(Node* head, Node* pre, int value) {

    Node* p = NULL;

    p = create_node(value);
    if (p == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    //새로 생성된 노드의 링크값으로 pre노드의 다음 노드 주소값 연결(할당)
    p->link = pre->link;
    //pre 노드의 링크필드에 새로 생성된 노드 주소를 할당
    pre->link = p;
    return head;
}*/
/*
Node* clear(Node* head) {
    Node* p = head;
    Node* temp = NULL;
    while (p!= NULL) {
        temp = p->link;
        
        p = p->link;
       
    }
    free(p);
   
    //head->link = NULL;
    head =NULL;
    
    return head;
}*/
Node* clear(Node* head) {
    Node* p = head;
    Node* temp = NULL;
    
    while (p->link!=NULL) {
        temp = p->link;//temp는 다음노드로 넘어감
        free(p);//노드 초기화
        p = temp;
    }
    free(p);
    head = NULL;
    return head;
}
void print_list(Node* head) {
    Node* p = head;


    //empty list
    if (p == NULL) {
        printf("Empty!\n");
        return;
    }
    //List is not empty
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->link;
    }
    printf("\n");



    return;
}
void count_list(Node* head) {
    Node* p = head;
    int count = 0;
    while (p != NULL) {

        //printf("%d ", p->data);
        count++;
        p = p->link;
    }
    printf("item 갯수는:%d\n", count);
    return ;
    
}
int is_in_list(Node* head, int item) {
    Node* p = head;
   

    while (p != NULL) {
        
        //printf("%d ", p->data);
        if (p->data == item) {
            printf("%d is in list\n", item);
            return TRUE;
        }
        p = p->link;
    }

    printf("%d is not in list\n", item);
    return FALSE;
}
void is_empty(Node* head) {
    Node* p = head;


    //empty list
    if (p == NULL) {
        printf("Empty!\n");
        return;
    }
    //List is not empty
    while (p != NULL) {
        printf("Not Empty!" );
        return;
    }
    printf("\n");

    return;
}
Node* delete_node(Node* head, int item) {
    Node* temp = head;
    Node* p = NULL;
    //head값이 삭제일때

    if (temp->data == item) {
        head = temp->link;
        free(temp);
        return head;
    }
    //head외의 값 삭제일때
    while (temp->link != NULL) {
      
        //printf("%d ", p->data);
        if (temp->link->data == item) {
            Node* p = temp->link;
            temp->link = p->link;
           
            free(p);
            return head;
        }
        temp = temp->link;

    }
    return head;
}
Node* delete_first(Node* head) {

    // Make temp as the first node
    Node* temp = head;

    if (temp != NULL)

        // If temp is the only node (i.e, first & last at the same time),
        // then, temp->link is NULL
        // Otherwise, temp is not the only node in the list,
        // then, temp->link points to the second node
        // Make head pointer point to either NULL or the address of the 2nd node
        head = temp->link;

    free(temp);

    return head;
}
/*
//pre가 가르키는거 delete
//노드 갯수가 1인경우 또는
//노드 개수가 2 이상이고, 두번째 이후 노드를 삭제할때 사용
Node* delete1(Node* head, Node* pre) {
    Node* temp = NULL;
    //노드갯수가 1인경우
    if (head->link == NULL) {
        temp = pre;
        head = NULL;

    }
    temp = pre->link;
    pre->link = temp->link;
    free(temp);

    return head;

}*/

int main() {

    Node* head = NULL;
    int i,item;
    printf("1.ADD  2.Delete  3.Clear 4.Search 5.Count 6.isEmpty 7.Print 8.Exit Program\n");
    while (1) {
        scanf("%d", &i);
       
        if (i == 1) {
            printf("item=");
            scanf("%d", &item);
            head = insert_first(head, item);
        }
        else if (i == 2) {
            printf("item=");
            scanf("%d", &item);
            head= delete_node(head, item);
        }
        else if (i == 3) {
            head=clear(head);
        }
        else if (i == 4) {
            printf("item=");
            scanf("%d", &item);
            is_in_list(head, item);
        }
        else if (i == 5) {
            count_list(head);
        }
        else if (i == 6) {
            is_empty(head);
        }
        else if (i == 7) {
            print_list(head);
        }
        else if (i == 8) {
            break;
        }

    }



    /*
    is_empty(head);
    head = insert_first(head, 10);
    
    head = insert(head, head, 25);
    head = insert_first(head, 20);
    
    head = insert_first(head, 30);
    head = insert(head, head, 25);
    
    print_list(head);
    is_empty(head);

    head = delete_first(head);
    print_list(head);
    head = delete_first(head);
    print_list(head);
    head = delete1(head, head->link);
    print_list(head);

    head = delete_first(head);
    print_list(head);
    head = delete_first(head);
    print_list(head);
    head = delete_first(head);

    head = insert_first(head, 100);
    head = insert(head, head, 200);
    //print_list(head);
    */
    return 0;
}