#include<stdio.h>

int main(){
    int n;
    printf("Enter the size of the array : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array : ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int temp = arr[0];
    int narr[n];
    printf("Enter the elements of the rotated array : ");
    for(int i=0;i<n;i++){
        scanf("%d",&narr[i]);
    }
    for(int i=0;i<n;i++){
        if(narr[i] == temp){
            printf("Value of K is %d",i);
        }
    }
}