//WAP to push, pop and display the stack using array....
// .....menu driven......
// 1. Push the data
// 2. Pop the data
// 3. Display the data
// 4. Exit from the program
//input.............................................
// Enter your choice: 1
// Enter a number you want to push: 10
//output.............................................
// 10 pushed from the stack

// .....menu driven......
// 1. Push the data
// 2. Pop the data
// 3. Display the data
// 4. Exit from the program
//input..............................................
// Enter your choice: 1
// Enter a number you want to push: 20
//output.............................................
// 20 pushed from the stack

// .....menu driven......
// 1. Push the data
// 2. Pop the data
// 3. Display the data
// 4. Exit from the program
//input...............................................
// Enter your choice: 2
//output.............................................
// 20 pop from the stack

// .....menu driven......
// 1. Push the data
// 2. Pop the data
// 3. Display the data
// 4. Exit from the program
//input...............................................
// Enter your choice: 3
//output..............................................
// The list is: 
// 10 


// .....menu driven......
// 1. Push the data
// 2. Pop the data
// 3. Display the data
// 4. Exit from the program
//input...............................................
// Enter your choice: 4
//output..............................................
// Exiting the program.

#include <stdio.h>
#include <stdbool.h>
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
    int val, choice;
    while(true){
        printf("\n.....menu driven......");
        printf("\n1. Push the data");
        printf("\n2. Pop the data");
        printf("\n3. Display the data");
        printf("\n4. Exit from the program");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: 
                printf("\nEnter a number you want to push: ");
                scanf("%d", &val);
                push(val);
                printf("\n");
                break;
            case 2: 
                pop();
                printf("\n");
                break;
            case 3: 
                display();
                printf("\n");
                break;
            case 4:
                printf("\nExiting the program.");
                return 0;
            default:
                printf("\nInvalid choice, please try again...");
                printf("\n");
        }
    }
return 0;
}