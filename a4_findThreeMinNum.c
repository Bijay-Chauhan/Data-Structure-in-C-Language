//WAP to find the first, second and the third smallest number of the array.....
//example ->

//input ->
//Enter a number you want to create the size of array : 7
// Enter your 1 number : 5
// Enter your 2 number : 11
// Enter your 3 number : 6
// Enter your 4 number : 3
// Enter your 5 number : 3
// Enter your 6 number : 3
// Enter your 7 number : 2

//output ->
// The first smallest number is : 2
// The second smallest number is : 3
// The third smallest number is : 3
#include <stdio.h>

int main() {
    int n;
    printf("Enter a number you want to create the size of array : ");
    scanf("%d",&n);
    int a[n];
    for(int i=0; i<n; i++){
        printf("\nEnter your %d number : ",i+1);
        scanf("%d",&a[i]);
    }
    int min1, min2, min3;
    min1 = min2 = min3 = a[0];
    for(int i=0; i<n; i++){
        if(a[i] < min1){
            min3 = min2;
            min2 = min1;
            min1 = a[i];
        }else if(a[i] < min2){
            min3 = min2;
            min2 = a[i];
        }else if(a[i] < min3){
            min3 = a[i];
        }
    }
    printf("\nThe first smallest number is : %d",min1);
    printf("\nThe second smallest number is : %d",min2);
    printf("\nThe third smallest number is : %d",min3);
return 0;
}