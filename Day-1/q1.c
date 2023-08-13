#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main()
{
    int n;
    printf("Enter array size : ");
    scanf("%d",&n);
    int arr[n];
    int lower,higher;
    printf("Enter lower range : ");
    scanf("%d",&lower);
    printf("Enter higher range : ");
    scanf("%d",&higher);
    printf("Elements of array : ");
    srand(time(0));
    for(int i=1;i<=n;i++)
    {
        arr[i] = (rand() % (higher-lower + 1)) + lower;
        printf("%d ",arr[i]);
    }
    printf("\n");
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    printf("Second smallest number : %d",arr[1]);
    printf("\nSecond largest number : %d",arr[n-2]);
}