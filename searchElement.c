//write a program to search the element of the index of the of the array n..
#include <stdio.h>
#include<stdlib.h>
int main() {
    int n=10;
    int *a;
    a= (int *)malloc(n* sizeof(int));
    for(int i=0;i<n;i++){
        printf("Enter your %d number: ",i+1);
        scanf("%d",a+i);
    }
    int x;
    printf("Enter Your choice number to search the element of the array: ");
    scanf("%d",&x);
    for(int i=0;i<n-1;i++){
        if(x==a[i]){
            printf("the searching element of the index is: %d",i);
            return 0;
        }
    }
return -1;
}
