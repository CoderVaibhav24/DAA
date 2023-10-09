#include<stdio.h>

int main(){
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int count =0;
    int sum = arr[0] + arr[1];
    printf("Printed elements : ");
    for(int i = 2;i<n;i++){
        if(sum < arr[i]){
            printf("%d ",arr[i]);
            count++;
        }else{
            sum += arr[i];
        }
    }
    if(count == 0){
        printf("None");
    }
    return 0;
}