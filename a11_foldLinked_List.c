//Write a program to fold a linked list (reorder list)
// ..................input.....................
// Enter number of nodes: 5
// Enter your 1 data: 1
// Enter your 2 data: 2
// Enter your 3 data: 3
// Enter your 4 data: 4
// Enter your 5 data: 5

// .................output..........................
// Original list:
// 1 -> 2 -> 3 -> 4 -> 5 -> NULL
// Folded list:
// 1 -> 5 -> 2 -> 4 -> 3 -> NULL

#include <stdio.h>
#include <stdlib.h>

//structure definition..
typedef struct node {
    int data;
    struct node *next;
} node;
node *head = NULL;

void insertEnd(int val);
node *createNode(int val);
void printList();
void foldList();
node* reverse(node *h2);

int main() {
    int n, val;
    printf("\nEnter number of nodes: ");
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        printf("\nEnter your %d data: ", i+1);
        scanf("%d", &val);
        insertEnd(val);
    }
    printf("\nOriginal list:\n");
    printList();
    foldList();
    printf("\nFolded list:\n");
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
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
//reverse a linked list
node* reverse(node *h2){
    node *prev = NULL, *next = NULL;
    node *curr = h2;
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev; // return new head
}
//fold the list
void foldList(){
    if (!head || !head->next) return;
    // Step 1: Find middle (slow/fast)
    node *slow = head, *fast = head;
    while(fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    node *mid = slow;
    // Step 2: Reverse second half
    node *h2 = reverse(mid->next);
    mid->next = NULL; // break the list
    // Step 3: Merge alternately
    node *h1 = head;
    node *tmp1, *tmp2;
    while(h2 != NULL){
        tmp1 = h1->next;
        tmp2 = h2->next;
        h1->next = h2;
        h2->next = tmp1;
        h1 = tmp1;
        h2 = tmp2;
    }
}
