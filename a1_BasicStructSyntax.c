//structure in c syntax in simple
#include <stdio.h>
struct student{//user defined data-type...
        int rollNo;
        float percentage;
    };
int main() {
    struct student detail;
    
    printf("enter your roll no.\n");
    scanf("%d",&detail.rollNo);
    printf("enter your percentage.\n");
    scanf("%f",&detail.percentage);
    
    printf("%d is the rollNo\n", detail.rollNo);
    printf("%f is the percentage\n", detail.percentage);
    return 0;
}