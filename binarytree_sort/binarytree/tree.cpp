// A simple implementation of binary search tree

#include<stdio.h>
#include<stdlib.h>

typedef struct bstnode {
    int data;
    struct bstnode* left;
    struct bstnode* right;
}Node;

Node* create_node(int x) {
    Node* p = (Node*)malloc(sizeof(Node));

    if (p == NULL) {
        printf("Memory allocation failed!!\n");
        exit(1);
    }

    p->data = x;
    p->left = NULL;
    p->right = NULL;

    return p;
}

Node* insert(Node* root, int x) {

    // If tree is empty
    if (root == NULL)
        root = create_node(x);

    // Otherwise
    else if (x <= root->data)  // Insert to the left subtree of the root node
        root->left = insert(root->left, x);
    else if (x > root->data)   // Insert to the right subtree of the root node
        root->right = insert(root->right, x);

    return root;
}

// Print all the nodes in the binary search tree
// visiting order: <Root> -> <Left subtree> -> <Right subtree>
void print_preorder(Node* root) {

    // Base case: tree is empty
    if (root == NULL)
        return;

    printf("%d ", root->data);
    print_preorder(root->left);
    print_preorder(root->right);

    return;
}

// Print all the nodes in the binary search tree
// visiting order: <Left subtree> -> <Root> -> <Right subtree>
void print_inorder(Node* root) {

    // Base case: tree is empty
    if (root == NULL)
        return;

    print_inorder(root->left);
    printf("%d ", root->data);
    print_inorder(root->right);

    return;
}

// Print all the nodes in the binary search tree
// visiting order: <Left subtree> -> <Right subtree> -> <Root>
void print_postorder(Node* root) {

    // Base case: tree is empty
    if (root == NULL)
        return;

    print_postorder(root->left);
    print_postorder(root->right);
    printf("%d ", root->data);

    return;
}

int main(void) {

    // Empty tree
    Node* root = NULL;

    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 25);
    root = insert(root, 6);
    root = insert(root, 15);
    root = insert(root, 23);
    root = insert(root, 30);
    root = insert(root, 17);

    printf("Preorder: ");
    print_preorder(root);
    printf("\n");

    printf("Inorder: ");
    print_inorder(root);
    printf("\n");

    printf("Postorder: ");
    print_postorder(root);
    printf("\n");

    return 0;
}