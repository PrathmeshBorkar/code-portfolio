#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100000

static int arr[MAX];

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    clock_t start, end;
    double total_time;

    printf("Enter number of elements to sort (Max %d): ", MAX);
    scanf("%d", &n);

    if (n > MAX) {
        printf("Exceeds maximum array limit!\n");
        return 1;
    }

    srand(time(0));

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100000;
    }

    printf("Sorting %d elements using Quick Sort...\n", n);

    start = clock();
    quickSort(arr, 0, n - 1);
    end = clock();

    total_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Quick Sort completed successfully!\n");
    printf("Time taken to sort %d elements: %f seconds\n", n, total_time);

    return 0;
}