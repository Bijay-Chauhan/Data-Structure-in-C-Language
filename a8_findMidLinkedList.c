//Write the linked list code to find the middle of the number...

//...................input................................
// Enter a number, you want take the size of node: 4
// Enter your 1 data: 11
// Enter your 2 data: 12
// Enter your 3 data: 13
// Enter your 4 data: 14

//..................output................................
// The middle of the list is: 13
// The element list is :
// 11 ->12 ->13 ->14 ->NULL

#include <stdio.h>
#include<stdlib.h>
//structure definition..
typedef struct node{
    int data;
    struct node *next;
}node;
node *head = NULL;

//function definition..........
void insertEnd(int val);
node *createNode(int val);
void printList();
void middleNode();

//main function....
int main() {
    int n, val;
    printf("\nEnter a number, you want take the size of node: ");
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        printf("\nEnter your %d data: ", i+1);
        scanf("%d", &val);
        insertEnd(val);
    }
    middleNode();
    printList();
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
//find the middle of the node function....
void middleNode(){
    node *fast;
    node *slow;
    fast = slow = head;
    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    printf("\nThe middle of the list is: %d", slow->data);
}