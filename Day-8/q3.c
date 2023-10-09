#include <stdio.h>

int main() {
    int n;
    printf("Length of expression (including the brackets): ");
    scanf("%d", &n);

    while (getchar() != '\n');

    char arr[n];
    printf("Enter the expression: ");

    for (int i = 0; i < n; i++) {
        scanf("%c", &arr[i]);
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] == '(' || arr[i] == ')') {
            continue;
        } else {
            printf("%c ", arr[i]);
        }
    }

    return 0;
}
