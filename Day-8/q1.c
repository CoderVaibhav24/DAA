#include <stdio.h>
#include <math.h>

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int lvl1, lvl2;
    printf("Starting level: ");
    scanf("%d", &lvl1);

    printf("Ending level: ");
    scanf("%d", &lvl2);

    int res1 = (int)pow(2, lvl1 - 1);
    int res2 = (int)pow(2, lvl2);

    // Check for valid levels
    if (lvl1 <= 0 || lvl2 <= 0 || lvl1 > lvl2 || res2 > n) {
        printf("Invalid level range.\n");
    } else {
        // Print the nodes between res1 and res2 (inclusive)
        for (int i = res1 - 1; i < res2 - 1; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    return 0;
}
