#include <stdio.h>

void max_heapify(int a[], int n, int i)
{
    int lc = 2 * i;
    int rc = 2 * i + 1;
    int gt = i;
    if (a[lc] > a[gt] && lc < n)
        gt = lc;
    if (a[rc] > a[gt] && rc < n)
        gt = rc;
    if (gt != i)
    {
        int temp = a[i];
        a[i] = a[gt];
        a[gt] = temp;
    }
}
void min_heapify(int a[], int n, int i)
{
    int lc = 2 * i;
    int rc = 2 * i + 1;
    int gt = i;
    if (a[lc] < a[gt] && lc < n)
        gt = lc;
    if (a[rc] < a[gt] && rc < n)
        gt = rc;
    if (gt != i)
    {
        int temp = a[i];
        a[i] = a[gt];
        a[gt] = temp;
    }
}

void build_heap(int a[], int n)
{
    for (int i = 1; i < n / 2; i++)
    {
        int b = i / 2;
        if (b % 2 == 0)
            min_heapify(a, n, i);
        else
            max_heapify(a, n, i);
    }
}

void print_array(int a[], int n)
{
    printf("New array : ");
    for (int i = 1; i <= n; i++)
        printf("%d ", a[i]);
}

int main()
{
    int n;
    printf("Size of the array : ");
    scanf("%d", &n);
    int a[n];
    printf("Elements of the array : ");
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    build_heap(a, n);
    print_array(a, n);
}