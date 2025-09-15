//WAP to push pop and display the stack using structures in c language.........
//...........output.................
// 10 pushed to stack
// 20 pushed to stack
// 30 pushed to stack
// Stack elements: 10 20 30
// Top element: 30
// Popped: 30
// Stack elements: 10 20
#include <stdio.h>
#include <stdlib.h>
#define MAX 5   // Maximum size of stack
// Structure for stack
struct Stack {
    int arr[MAX];
    int top;
};
// Function to initialize stack
void init(struct Stack *s) {
    s->top = -1;
}
// Check if stack is empty
int isEmpty(struct Stack *s) {
    return s->top == -1;
}
// Check if stack is full
int isFull(struct Stack *s) {
    return s->top == MAX - 1;
}
// Push element onto stack
void push(struct Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow! Cannot push %d\n", value);
        return;
    }
    s->arr[++(s->top)] = value;
    printf("%d pushed to stack\n", value);
}
// Pop element from stack
int pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow!\n");
        return -1;
    }
    return s->arr[(s->top)--];
}
// Peek at top element
int peek(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return -1;
    }
    return s->arr[s->top];
}
// Display stack elements
void display(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}
//main function
int main() {
    struct Stack s;
    init(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    display(&s);

    printf("Top element: %d\n", peek(&s));
    printf("Popped: %d\n", pop(&s));
    display(&s);
return 0;
}
