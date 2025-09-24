//Write a binary tree to find the maximum height of the tree.

//...........output.................
// Inorder traversal   : 10 20 30 35 40 50 60 65 70 80 
// The max height is :4

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
int height(node *root);

int main() {
    node *root = NULL;
    int values[10] = {50, 30, 70, 20, 40, 60, 80, 10, 35, 65};
    for (int i = 0; i < 10; i++) {
        root = insert(root, values[i]);
    }
    printf("\nInorder traversal   : ");
    inorder(root);
    int maxHeight = height(root);
    printf("\nThe max height is :%d", maxHeight);

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
int height(node *root){
    if(root == NULL){
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);
    if(left < right){
        return ( right + 1 );
    }else{
        return ( left + 1 );
    }
}