//WAP to push, pop and display the stack using array....
// .......................output.................................
// 10 pushed from the stack
// 20 pushed from the stack
// 30 pushed from the stack
// 40 pushed from the stack
// The list is: 
// 40 
// 30 
// 20 
// 10 
// 40 pop from the stack
// The list is: 
// 30 
// 20 
// 10 

#include <stdio.h>
#define MAX 5
int stack[MAX];
int top = -1;

//for push function....
void push(int x){
    if(top == MAX - 1){
        printf("stack overflow");
    }else{
        top++;
        stack[top] = x;
        printf("\n%d pushed from the stack", x);
    }
}
//function for pop....
void pop(){
    if(top == -1){
        printf("stack underflow");
    }else{
        printf("\n%d pop from the stack", stack[top]);
        top--;
    }
}
//function for display...
void display(){
    if(top == -1){
        printf("\nthe list is empty");
    }else{
        printf("\nThe list is: \n");
        for(int i=top; i>=0; i--){
            printf("%d \n", stack[i]);
        }
    }
}
//for main function...
int main() {
    push(10);
    push(20);
    push(30);
    push(40);
    display();
    pop();
    display();
return 0;
}