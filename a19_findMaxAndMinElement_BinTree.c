//Write a binary tree to find the maximum number element and minimum no. of element in an tree.

//...........output.................
// Inorder traversal   : 10 20 30 35 40 50 60 65 70 80 
// The maximum no. of element is :80
// The minimum no. of element is :10

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

// Function prototypes
node* insert(node *root, int val);
node* createNode(int val);
void inorder(node *root);
int maxElement(node *root);
int minElement(node *root);

int main() {
    node *root = NULL;
    int values[10] = {50, 30, 70, 20, 40, 60, 80, 10, 35, 65};
    for (int i = 0; i < 10; i++) {
        root = insert(root, values[i]);
    }
    printf("\nInorder traversal   : ");
    inorder(root);
    int Node = maxElement(root);
    printf("\nThe maximum no. of element is :%d", Node);
    int Node1 = minElement(root);
    printf("\nThe minimum no. of element is :%d", Node1);

    return 0;
}
// Create new node
node *createNode(int val) {
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}
// Insert node in BST
node *insert(node *root, int val) {
    if (root == NULL) {
        return createNode(val);
    }
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else if (val > root->data) {
        root->right = insert(root->right, val);
    }
    return root;
}
// Inorder traversal (Left, Root, Right)
void inorder(node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
//function for find the max element...
int maxElement(node *root){
    while(root != NULL && root->right != NULL){
        root = root->right;
    }
    return root->data;
}
//function for find the min element...
int minElement(node *root){
    while(root != NULL && root->left != NULL){
        root = root->left;
    }
    return root->data;
    
}