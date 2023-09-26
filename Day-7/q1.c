#include <stdio.h>
#include <stdlib.h>

struct Item {
    double value;
    double weight;
    double value_per_weight;
};

void swap(struct Item* a, struct Item* b) {
    struct Item temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(struct Item items[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && items[left].value_per_weight > items[largest].value_per_weight)
        largest = left;

    if (right < n && items[right].value_per_weight > items[largest].value_per_weight)
        largest = right;

    if (largest != i) {
        swap(&items[i], &items[largest]);
        heapify(items, n, largest);
    }
}

void heapSort(struct Item items[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(items, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(&items[0], &items[i]);
        heapify(items, i, 0);
    }
}

int main() {
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    struct Item items[n];

    for (int i = 0; i < n; i++) {
        printf("Enter the Value and Weight of item %d: ", i + 1);
        scanf("%lf %lf", &items[i].value, &items[i].weight);
        items[i].value_per_weight = items[i].value / items[i].weight;
    }

    printf("Enter the capacity of knapsack: ");
    double capacity;
    scanf("%lf", &capacity);
    heapSort(items, n);

    double maxProfit = 0.0;
    double amounts[n]; 

    printf("\nItem No\tValue\t\tWeight\t\tAmount to be taken\n");
    for (int i = n-1; i >=0; i--) {
        if (capacity >= items[i].weight) {
            amounts[i] = 1.0;
            capacity -= items[i].weight;
        } else {
            amounts[i] = capacity / items[i].weight;
            capacity = 0;
        }
        maxProfit += items[i].value * amounts[i];
        printf("%d\t%.6lf\t%.6lf\t%.6lf\n", i + 1, items[i].value, items[i].weight, amounts[i]);
    }

    printf("\nMaximum profit: %.6lf\n", maxProfit);

    return 0;
}
