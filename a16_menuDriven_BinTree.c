//write a binary tree menu driven

// ....binary menu driven....
// 1. Insert data.
// 2. inorder traverser.
// 3. preorder traverser.
// 4. postorder traverser.
// 5. search.
// 6. find Minimum no.
// 7. find Maximum number.
// 8. Quit.
//input...........
// Enter your choice: 1
// Enter a value for insert : 5
//output............
// 5 value inserted

// Enter your choice: 1
// Enter a value for insert : 5
// 5 value inserted

// Enter your choice: 1
// Enter a value for insert : 3
// 3 value inserted

// Enter your choice: 2
// Inorder traverser.3	5	
// Enter your choice: 

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}node;
//prototype defintion 
node*insert(node *root, int val);
node *createNode(int val);
void inorder(node *root);
void preorder(node *root);
void postorder(node *root);
node *search(node *root, int val);
node *findMin(node *root);
node *findMax(node *root);

int main() {
    node *root = NULL;
    int choice, val;
    printf("\n....binary menu driven....");
    printf("\n1. Insert data.");
    printf("\n2. inorder traverser.");
    printf("\n3. preorder traverser.");
    printf("\n4. postorder traverser.");
    printf("\n5. search.");
    printf("\n6. find Minimum no.");
    printf("\n7. find Maximum number.");
    printf("\n8. Quit.");
    while(1){
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: 
                printf("\nEnter a value for insert : ");
                scanf("%d", &val);
                root = insert(root, val);
                printf("\n%d value inserted", val);
                break;
            case 2:
                printf("\nInorder traverser.");
                inorder(root);
                break;
            case 3:
                printf("\npreorder traverser.");
                preorder(root);
                break;
            case 4:
                printf("\nPostorder traverser.");
                postorder(root);
                break;
            case 5:
                printf("\nEnter a value for search in tree: ");
                scanf("%d", &val);
                if(search(root, val)){
                    printf("\n%d is found in tree", val);
                }else{
                    printf("\n%d is not found in tree", val);
                }
                break;
            case 6: 
                if(root){
                    int min = findMin(root)->data;
                    printf("\nThe minimum number is: %d", min);
                }else{
                    printf("\nroot is empty.");
                }
                break;
            case 7: 
                if(root != NULL){
                    int max = findMax(root)->data;
                    printf("\nThe maximum number is: %d", max);
                }else{
                    printf("\nroot is empty.");
                }
                break;
            case 8: 
                printf("\nExisting program.");
                exit(0);
            default: 
                printf("\nInvalid choice, please try again!");
        }
    }
    
    return 0;
}
//create node function........
node *createNode(int val){
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}
//insert node function.....
node *insert(node *root, int val){
    if(root == NULL){
        return createNode(val);
    }
    if(val < root->data){
        root->left = insert(root->left, val);
    }else if(val > root->data){
        root->right = insert(root->right, val);
    }
    return root;
}
//function for inorder traverser....
void inorder(node *root){
    if(root != NULL){
        inorder(root->left);
        printf("%d\t", root->data);
        inorder(root->right);
    }
}
//function for preorder traverser...
void preorder(node *root){
    if(root != NULL){
        printf("%d\t", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
//function for post order...
void postorder(node *root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d\t", root->data);
    }
}
//search element in tree...
node *search(node *root, int val){
    if(root == NULL || root-> data == val){
        return root;
    }
    if(val < root->data){
        return search(root->left, val);
    }else{
        return search(root->right, val);
    }
}
//find the minimum number...
node *findMin(node *root){
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}
//find the maximum number...
node *findMax(node *root){
    while(root->right != NULL){
        root = root->right;
    }
    return root;
}