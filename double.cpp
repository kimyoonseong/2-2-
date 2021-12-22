#define _CRT_SECURE_NO_WARNINGS
#define MAX_STACK_SIZE 5
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#define TRUE 1;
#define FALSE 0;
typedef struct node {
    char* data;
    struct node* prev;
    struct node* next;
}Node;

Node* create_node(char *value) {

    Node* temp = NULL;
    temp = (Node*)malloc(sizeof(Node));
    if (temp == NULL) {
        printf("Memory allocation failed!!\n");
        exit(1);
    }
    temp->data=(char* )malloc(sizeof(char)*20);
    /*
    if (temp->data == NULL) {
        printf("Memory allocation failed!!\n");
        exit(1);
    }*/
    strcpy(temp->data, value);
    //temp->data = value;
    temp->prev = NULL;//Header
    temp->next = NULL;//Trailer

    return temp;
}
/*
Node* insert_first(Node* head, int value) {

    Node* temp = NULL;

    temp = create_node(value);
    if (temp != NULL) {
        // Make temp node as the first node
        // The next node of the temp is the previously first node
        temp->link = head;

        // Make head pointer point to temp node
        head = temp;
    }
    return head;
}*/
/*
// value ���� ���� ���� ��, pre �����Ͱ� ����Ű�� ��� ������ ����
Node* insert(Node* head, Node* before, int value) {
    Node* p = NULL;

    p = (Node*)create_node(value);

    //���� ��带 ����ϴ� ����� ���� ����Ʈ���� ��� �߰�
    //���� �߰��ϴ� ����� prev���� �����Ϸ��� ���� ���� ��� �ּҷ� �Ҵ�
    p->prev = before;

    //���� �߰��ϴ� ��� next���� �����Ϸ��� ���� ���� ��� �ּҷ� �Ҵ�
    p->next = before->next;

    //�߰��� ��� ���� ����� prev���� �߰��� ��� �ּ� �Ҵ�(�� ������ ��带 ����)
    before->next->prev = p;

    //�߰��� ��� ���� ����� next ���� �߰��� ��� �ּ� �Ҵ�(�� ���� ��带 ����)
    before->next = p;
    return head;
}
*/
Node* add_node(Node* head, char* str) {
    Node* p = NULL;
    p = (Node*)create_node(str);

    p->prev = head;
    p->next = head->next;
    head->next->prev = p;
    head->next = p;
    return head;
}

// Delete a node after the node pointed by pre

Node* Delete(Node* head, Node* p) {
    //������� ������ ����� next
    p->prev->next = p->next;
    p->next->prev = p->prev;

    free(p);

    return head;
}
/*
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
*/
void print_list(Node* head) {
    Node* p = head->next;
    if (p->next == NULL) {//trailer����Ű�°���!
        printf("List is empty!!\n");
        exit(1);
    }

    while (p->next != NULL) {
        printf("%s ", p->data);
        p = p->next;
    }
    printf("\n");

    return;
}
int is_empty(Node* head) {
    Node* p = head->next;
    if (p->next == NULL) {//trailer����Ű�°���!
        printf("List is empty!!\n");
        return TRUE;
    }
    else {
        printf("List is not empty!!\n");
        return FALSE;
    }
    
}
void count_list(Node* head) {
    Node* p = head->next;
    int count = 0;
    if (p->next == NULL) {
        printf("Node�� ������ %d\n", count);
        return;
    }
    while (p->next != NULL) {
        count++;
        //printf("%d ", count);
        p = p->next;
    }
    
    printf("Node�� ������ %d\n",count);
    return;
}
int is_in_list(Node* head, char* str) {
    Node* p = head->next;
    //head ������ ������
    
    if (p->next== NULL) {
        printf("%s is not in list\n", str);
        return FALSE;
    }
    while (p->next != NULL) {
        //printf("%s       %s\n", p->data,str);
        while (strcmp(p->data, str) == 0) {
            //printf("%s %s", str, p->data);
            printf("%s is  in list\n", str);
            return TRUE;
        }
        
        
        p = p->next;
     }
     
     printf("%s is not is list\n", str);
     return FALSE;
     
}
void search(Node* head, char* str) {
    Node* p = head->next;
    //head ������ ������

    if (p->next == NULL) {
        printf("%s is not in list\n", str);
        return ;
    }
    while (p->next != NULL) {
        //printf("%s       %s\n", p->data,str);
        while (strcmp(p->data, str) == 0) {
            //printf("%s %s", str, p->data);
            printf("�ش� ����� �ּ�=%p\n", &p);
            return ;
        }


        p = p->next;
    }

    printf("%s is not is list\n", str);
    return ;
}
int main() {

    Node header, trailer;

    //�ΰ��� ���̳�� �ʱ�ȭ
    header.prev = NULL;
    header.next = &trailer;
    trailer.prev = &header;
    trailer.next = NULL;

    
    Node* head = &header;
    Node* p = head;
    char app[20];
    int i;
    printf("1.ADD  2.Delete  3.isinlist 4.Count 5.isEmpty 6.Print 7.Search 8.Exit Program\n");
    while (1) {
        scanf("%d", &i);

        if (i == 1) {
            printf("app�̸�:");
            scanf("%s", app);
            head = add_node(head, app);
        }
        else if (i == 2) {
            head = Delete(head, head->next);//ù��° ����
        }
        else if (i == 3) {
            printf("app�̸�:");
            scanf("%s", app);
            is_in_list(head, app);
        }
        else if (i == 4) {
            count_list(head);
        }
        else if (i == 5) {
            is_empty(head);
        }
        else if (i == 6) {
            print_list(head);
        }
        else if (i == 7) {
            printf("app�̸�:");
            scanf("%s", app);
            search(head, app);
        }
        else if (i == 8) {
            break;
        }

    }
    
    //char str[20] ;
    //scanf("%s",str);
    //head�����ʹ� header dummy node����Ų��
    //Node* head = &header;
    //head = add_node(head, str);
    //print_list(head);
    /*
    // header ���� ��� ������ �� 10�� �߰�
    head = insert(head, head, 10);

    // header ���� ��� ������ �� 20�� �߰�
    head = insert(head, head, 20);
    // ù��° ��� ������ �� 15�� �߰�
    head = insert(head, head->next, 15);
    print_list(head);

    //ù��°������
    head = Delete(head, head->next);
    print_list(head);
    //�ι�°������(�� ���⼭�¤� ������ ���) ����
    head = Delete(head, head->next->next);
    print_list(head);
    //ù��°������(�� ���⼭�¤� ������ ���) ����
    head = Delete(head, head->next);
    print_list(head);
   */
    return 0;
}