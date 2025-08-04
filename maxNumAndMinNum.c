//2. Write a C program to input 10 numbers in an array and find the maximum and minimum number from the array.
#include<stdio.h>
int main(){

int arr[10];
for(int i=1;i<=10;i++){
   printf("Enter your %dth number: \n",i);
   scanf("%d",&arr[i]);
}
//printing for maximum number
int max=arr[0];
for(int i=1;i<10;i++){
   if(arr[i]>max){
      max = arr[i];
   }
}
printf("The maximum number is :%d\n",max);
//finding the minimum number...
int min=arr[0];
for(int i=1;i<10;i++){
   if(arr[i]<min){
      min = arr[i];
   }
}
printf("The minimum number is :%d\n",min);
return 0;
}
