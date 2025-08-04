//create the function that print all the even no present in odd index......
#include <stdio.h>

int main() {
    int arr[2][2];
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            printf("enter the size of arr %d: ",i+1);
            scanf("%d",&arr[i][j]);
        }
    }
    printf("\n");
    printf("......................................\n");
    for(int i=0;i<2;i++){
        for(int j=2;j>=i;j--){
            int temp=arr[i][j];
            arr[i][j]=arr[j][i];
            arr[j][i]=temp;
        }
    }
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            printf("%d  ",arr[i][j]);
        }
        printf("\n");
    }
    

    return 0;
}