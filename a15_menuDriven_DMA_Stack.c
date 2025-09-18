// Write a menu driven program to perform the following operations of a stack using suitable user defind functions for each case
// a) Check if the stach is empty. 
// b) Display the contents of stack. 
// c) Push 
// d) Pop

#include <stdio.h>
#include <stdlib.h>
// Structure of stack
typedef struct stack {
    int size;
    int top;
    int *a;  // dynamic array
} stack;
// Function to create stack
stack* createStack(int size) {
    stack *s = (stack*)malloc(sizeof(stack));
    s->size = size;
    s->top = -1;
    s->a = (int*)malloc(sizeof(int) * size);
    return s;
}
// Push function
void Push(stack *s, int val) {
    if (s->top == s->size - 1) {
        printf("\nStack Overflow! Cannot push %d.", val);
        return;
    }
    s->a[++s->top] = val;
    printf("\nPushed %d", val);
}
// Pop function
void Pop(stack *s) {
    if (s->top == -1) {
        printf("\nStack Underflow! Nothing to pop.");
        return;
    }
    printf("\nPopped %d", s->a[s->top--]);
}
// Display function
void displayStack(stack *s) {
    if (s->top == -1) {
        printf("\nStack is empty.");
        return;
    }
    printf("\nStack contents (top to bottom): ");
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->a[i]);
    }
    printf("\n");
}
// Check if stack is empty
void checkEmpty(stack *s) {
    if (s->top == -1) {
        printf("\nStack is empty.");
    } else {
        printf("\nStack is not empty.");
    }
}
int main() {
    int size, val, choice;
    printf("Enter size of stack: ");
    scanf("%d", &size);
    stack *s = createStack(size);
    while (1) {
        printf("\n\n--------- Stack Menu ---------");
        printf("\n1. Check if stack is empty");
        printf("\n2. Display stack elements");
        printf("\n3. Push element");
        printf("\n4. Pop element");
        printf("\n5. Quit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                checkEmpty(s);
                break;
            case 2:
                displayStack(s);
                break;
            case 3:
                printf("\nEnter value to push: ");
                scanf("%d", &val);
                Push(s, val);
                break;
            case 4:
                Pop(s);
                break;
            case 5:
                free(s->a);
                free(s);
                printf("\nExiting program.\n");
                exit(0);
            default:
                printf("\nInvalid choice! Try again.");
        }
    }
    return 0;
}
