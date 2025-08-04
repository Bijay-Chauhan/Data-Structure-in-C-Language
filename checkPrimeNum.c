//3. Write a C program to check whether a given number is a prime number or not using logical operators.
//0 and 1 ->not prime number
// 2, 3, 5, 7, 11,....is the prime number
#include<stdio.h>
int main(){

int n;
printf("Enter your number,Your want to check the number is prime or not :");
scanf("%d",&n);
int prime=1;
if(n<=1){
  prime = 0;
}
for(int i=2;i<=n/2;i++){
   if(n%i==0){
      prime = 0;
      break;
   }
}
if(prime){
   printf("The number %dth is a prime number.",n);
}else{
   printf("The number %dth is not a prime number.",n);
}
printf("\n");
return 0;
}