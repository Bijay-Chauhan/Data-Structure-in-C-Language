//WAP to print the linked list code.....
//    input ->
// Enter a number, you want take the size of node: 5
// Enter your 1 data: 10
// Enter your 2 data: 15
// Enter your 3 data: 20
// Enter your 4 data: 25
// Enter your 5 data: 30
//    Output ->
// The Linked list is :
// 10 ->15 ->20 ->25 ->30 ->NULL
//    input ->
//Enter a number, you want to add at the start: 5
//    output ->
// The Linked list is :
// 5 ->10 ->15 ->20 ->25 ->30 ->NULL

#include <stdio.h>
#include<stdlib.h>
//structure definition..
typedef struct node{
    int data;
    struct node *next;
}node;
//print the data inside the node...
void printList(node *head){
    node *temp = head;
    printf("\nThe Linked list is :\n");
    while(temp != NULL){
        printf("%d ->",temp->data);
        temp = temp->next;
    }
    printf("NULL");
}
//create the node...
node *createNode(int val){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}
//insert the new node value in the start..
void insertStart(node **head, int st){
    node *newNode = createNode(st);
    newNode->next = *head;
    *head = newNode;
}
//take the data and insert the node....
void insertEnd(node **head, int val){
    node *newNode = createNode(val);
    if(*head == NULL){
        *head = newNode;
        return;
    }
    node *temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}
int main() {
    int n, val, st;
    node *head = NULL;
    printf("Enter a number, you want take the size of node: ");
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        printf("Enter your %d data: ", i+1);
        scanf("%d", &val);
        insertEnd(&head, val);
    }
    printList(head);
    printf("\nEnter a number, you want to add at the start: ");
    scanf("%d",&st);
    insertStart(&head, st);
    printList(head);
    return 0;
}