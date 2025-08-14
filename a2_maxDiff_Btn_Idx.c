//WAP to find the maximum difference between index i, j...
//example -> given array 
// input -> arr[] = {5, 3, 6, 2, 7}
// ans -> the maximum difference of index is : 4
#include <stdio.h>

int main() {
    int a[] = {5,9,6,2,7};
    int i = 4;
    int j = 0;
    int curr = 0, maxIdx = 0;
    while(i>=j){
        if(a[i] > a[j]){
            curr = i - j;
        }
        if(curr > maxIdx){
            maxIdx = curr;
        }
        if(a[j] > a[i]){
            j++;
        }else{
            i--;
        }
    }
printf("The maximum difference of index is : %d",maxIdx);
return 0;
}