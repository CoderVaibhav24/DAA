#include<stdio.h>

int main()
{
    int n;
    printf("Enter the size of the array : ");
    scanf("%d",&n);
    int arr[n];
    int temp = 1;
    printf("Enter the array elements : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        temp *= arr[i];
    }
    printf("Output array : ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",temp/arr[i]);
    }
}