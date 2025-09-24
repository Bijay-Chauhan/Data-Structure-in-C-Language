//Write a binary tree to find the number of node in an tree.

//...........output.................
// Inorder traversal   : 10 20 30 35 40 50 60 65 70 80 
// The total node is :10


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
int totalNode(node *root);

int main() {
    node *root = NULL;
    int values[10] = {50, 30, 70, 20, 40, 60, 80, 10, 35, 65};
    for (int i = 0; i < 10; i++) {
        root = insert(root, values[i]);
    }
    printf("\nInorder traversal   : ");
    inorder(root);
    int Node = totalNode(root);
    printf("\nThe total node is :%d", Node);

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
//function for find the max height...
int totalNode(node *root){
    if(root == NULL){
        return 0;
    }
    int left = totalNode(root->left);
    int right = totalNode(root->right);
    return (left + right + 1);
}