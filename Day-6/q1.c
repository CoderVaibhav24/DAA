#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct person {
    int id;
    char *name;
    int age;
    int height;
    int weight;
};

void swap(struct person *a, struct person *b) {
    struct person temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(struct person arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].height > arr[largest].height)
        largest = left;

    if (right < n && arr[right].height > arr[largest].height)
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(struct person arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    FILE *file = fopen("dat1000.csv", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    int max_persons = 100;
    struct person *persons = malloc(max_persons * sizeof(struct person));
    int num_persons = 0;

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        char *token = strtok(line, ",");
        persons[num_persons].id = atoi(token);

        token = strtok(NULL, ",");
        persons[num_persons].name = strdup(token);

        token = strtok(NULL, ",");
        persons[num_persons].age = atoi(token);

        token = strtok(NULL, ",");
        persons[num_persons].height = atoi(token);

        token = strtok(NULL, ",");
        persons[num_persons].weight = atoi(token);

        num_persons++;

        if (num_persons >= max_persons) {
            max_persons *= 2;
            persons = realloc(persons, max_persons * sizeof(struct person));
        }
    }

    fclose(file);
    clock_t start = clock();
    heapSort(persons, num_persons);
    clock_t end = clock();
    double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Time taken for sorting: %f seconds\n", elapsed_time);
    for (int i = 0; i < num_persons; i++) {
        free(persons[i].name);
    }
    free(persons);

    return 0;
}
