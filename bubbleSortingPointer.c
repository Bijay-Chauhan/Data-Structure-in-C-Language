//WAP to print the ascending order using Dynamic memory allocation...
//arr[10]={1,3,5,7,9,11,2,4,6,8}
//The sorted arr is
////arr[10]={1,2,3,4,5,6,7,8,9,11}
#include <stdio.h>
#include<stdlib.h>
int main() {
    int n=10;
    int *a;
    //taking memory allocation for array
    a= (int *)malloc(n* sizeof(int));
    //looping for input 10 number
    for(int i=0;i<n;i++){
        printf("Enter your %d number: ",i+1);
        scanf("%d",a+i);
    }
    int temp;
    //sorting part
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1;j++){
             if(a[j]>a[j+1]){
                 temp= a[j];
                 a[j]=a[j+1];
                 a[j+1]=temp;
             }
        }
    }
    //after sorting print the array
    printf("the sorted number is:\n");
    for(int i=0;i<n;i++){
        printf("%d \n",a[i]);
    }
    return 0;
}
