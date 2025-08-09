//WAP to to input a digit and print the reverse and also print the number is palindrom number or not...
//example-1.....
    //input: 123456
    //output: the reverse number is: 654321
    //the number is not palindrom number.
    
//example-1.....
    //input: 123321
    //output: the reverse number is: 123321
    //the number is palindrom number.
#include <stdio.h>

int main() {
    int n;
    printf("Enter digit to check the number is palindrom number: ");
    scanf("%d",&n);
    int first=n;
    long reverse=0;
    //convert the number into reverse...
    while(n!=0){
        int digit=n%10;
        reverse = reverse*10 + digit;
        n/=10;
    }
    //print the reverse number...
    printf("the reverse digit is: %d",reverse);
    //check the number is palindrom number 
    if(first==reverse){
        printf("\nthe number is palindrom number.");
    }else{
        printf("\nthe number is not palindrom number.");
    }
    return 0;
}