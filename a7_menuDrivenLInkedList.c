// Write a menu driven program to perform the following operation in a single linked list using self-referencing structure and suitable user defined function for each case.
//........input ->.................
// // The menu choice:
// 1: Traversal
// 2: Empty checking
// 3: Insert the node at begining
// 4: Insert the node at end
// 5: Insert the node at a position
// 6: Delete the node from begining
// 7: Delete the node from end
// 8: Delete the node at a position
// 9: Total number of nodes
// 10: Search the element
// 11: Quit
// Enter a number, you want take the size of node: 2
// Enter your 1 data: 11
// Enter your 2 data: 12
// Enter your choice to call using menu number: 11
//.............output->................................
// The linked list is deleted and memory deallocated. Hence, quiting from the program.

#include <stdio.h>
#include<stdlib.h>
//structure definition..
typedef struct node{
    int data;
    struct node *next;
}node;
node *head = NULL;

void insertEnd(int val);
node *createNode(int val);
void printList();
int isEmpty();
void insertAtBegin();
void insertAtEnd();
void insertNodeAtPosition();
void deletAtStart();
void deleteAtEnd();
void deleteAtPosition();
void totalNode(int n);
int searchElement();
void quit();

int main() {
    int n, val;
    printf("\nThe menu choice:");
    printf("\n1: Traversal");
    printf("\n2: Empty checking");
    printf("\n3: Insert the node at begining");
    printf("\n4: Insert the node at end");
    printf("\n5: Insert the node at a position");
    printf("\n6: Delete the node from begining");
    printf("\n7: Delete the node from end");
    printf("\n8: Delete the node at a position");
    printf("\n9: Total number of nodes");
    printf("\n10: Search the element");
    printf("\n11: Quit");
    
    printf("\nEnter a number, you want take the size of node: ");
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        printf("\nEnter your %d data: ", i+1);
        scanf("%d", &val);
        insertEnd(val);
    }
    int userChoice;
    printf("\nEnter your choice to call using menu number: ");
    scanf("%d",&userChoice);
    switch(userChoice){
        case 1: printList();
                break;
        case 2: isEmpty();
                break;
        case 3: insertAtBegin();
                break;
        case 4: insertAtEnd();
                break;
        case 5: insertNodeAtPosition();
                break;
        case 6: deletAtStart();
                break;
        case 7: deleteAtEnd();
                break;
        case 8: deleteAtPosition();
                break;
        case 9: totalNode(n);
                break;
        case 10:searchElement();
                break;
        case 11:quit();
                break;
    }
    return 0;
}
//create the node...
node *createNode(int val){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

//insert at the end.....
void insertEnd(int val){
    node *newNode = createNode(val);
    if(head == NULL){
        head = newNode;
        return;
    }
    node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}
//print the data inside the node...
void printList(){
    node *temp = head;
    printf("\nThe element list is :\n");
    while(temp != NULL){
        printf("%d ->",temp->data);
        temp = temp->next;
    }
    printf("NULL");
}
//check the list is empty or not...
int isEmpty(){
    if(head == NULL){
        printf("\nThe list is empty.");
    }else{
        printf("\nThe list is not empty.");
    }
}
//insert the new node value in the start..
void insertAtBegin(){
    int st;
    printf("\nEnter a number, you want to insert at the begin: ");
    scanf("%d",&st);
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = st;
    newNode->next = head;
    head = newNode;
    node *temp = head;
    printf("\nThe element list is :\n");
    while(temp != NULL){
        printf("%d ->",temp->data);
        temp = temp->next;
    }
    printf("NULL");
}
//insert the new value at the end....
void insertAtEnd(){
    int end;
    printf("\nEnter a number, you want to insert at the end: ");
    scanf("%d",&end);
    node *newNode = createNode(end);
    if(head == NULL){
        head = newNode;
        return;
    }
    node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    printList();
}
//insert node at a position...
void insertNodeAtPosition(){
    int x, val;
    printf("\nEnter data to insert at a position: ");
    scanf("%d",&val);
    printf("\nEnter position to insert at a position: ");
    scanf("%d",&x);
    node *newNode = createNode(val);
    if(x == 1){
        newNode->next = head;
        head = newNode;
        return;
    }
    node *temp = head;
    for(int i=1; i<x-1 && temp!=NULL; i++){
        temp = temp->next;
    }
    if(temp == NULL){
        printf("\nThe position is out of range.");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    printList();
}
//delete the node at the start position....
void deletAtStart(){
    if(head == NULL){
        printf("\nThe List is empty.");
        return;
    }
    node *temp = head;
    head = head->next;
    free(temp);
    printList();
}
void deleteAtEnd(){
    if(head == NULL){
        printf("\nThe List is empty.");
        return;
    }
    if(head->next == NULL){
        free(head);
        head = NULL;
        return;
    }
    node *temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    free (temp->next);
    temp->next = NULL;
    printList();
}
//delete the node at the start position....
void deleteAtPosition(){
    int pos;
    printf("\nEnter a position number, you want to delete: ");
    scanf("%d",&pos);
    if(pos == 1){
        node *temp = head;
        head = head->next;
        free(temp);
        return;
    }
    node *temp = head;
    for(int i=1; i<pos-1 && temp!=NULL; i++){
        temp = temp->next;
    }
    if(temp == NULL && temp->next == NULL){
        printf("\nThe position is out of range.");
        return;
    }
    node *delNode = temp->next;
    temp->next = delNode->next;
    free(delNode);
    printList();
}
void totalNode(int n){
    printf("\nThe total number of node is: %d",n);
    return;
}
//search the element inside the node...
int searchElement(){
    int search, count=1;
    printf("\nEnter a number to search: ");
    scanf("%d",&search);
    node *temp = head;
    while(temp != NULL){
        if(temp->data == search){
            printf("\nThe search index is: %d",count);
            return 0;
        }
        temp = temp->next;
        count++;
    }
    return -1;
}
void quit(){
    free(head);
    printf("\nThe linked list is deleted and memory deallocated. Hence, quiting from the program.");
    return;
}