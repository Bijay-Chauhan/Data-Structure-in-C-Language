//Write a C program using switch-case to implement a simple calculator that performs +, -, *, /
//based on user input.

#include<stdio.h>
int main(){

  int a,b;
  printf("Enter Your first number:\n ");
  scanf("%d",&a);
  printf("Enter Your second number:\n");
  scanf("%d",&b);
  //input number you want to add, substract, multiply, and division
  int i;
  printf("if You want to add, then Enter :1\n");
  printf("if You want to substract, then Enter :2\n");
  printf("if You want to multiply, then Enter :3\n");
  printf("if You want to divide, then Enter :4\n");
  scanf("%d",&i);
  switch(i){
  //case 1 for add the number
  case 1:
    int sum=a+b;
    printf("The sum of %d and %d number is %d",a,b,sum);
    break;
  //case 2 for substract the number
  case 2:
    int sub=a-b;
    printf("The substract of %d and %d number is %d",a,b,sub);
    break;
  //case 3 for multiply the number
  case 3:
    int pro=a*b;
    printf("The product of %d and %d number is %d",a,b,pro);
    break;
   //case 4 for divide the number
  case 4: 
    int div=a/b;
    printf("The division of %d and %d number is %d",a,b,div);
    break;
  //default the number
  default:
  printf("Your enter number is invalid. please enter the correct number.");
  }
return 0;
}
