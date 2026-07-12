#include <stdio.h>

int binary_search(int arr[], int low, int high, int s) {
    if (low > high)
        return -1;

    int mid = (low + high) / 2;

    if (arr[mid] == s)
        return mid;
    else if (arr[mid] < s)
        return binary_search(arr, mid + 1, high, s);
    else
        return binary_search(arr, low, mid - 1, s);
}

int main() {
    int n, s;

    printf("Enter size of array : ");
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++) 
    {
        printf("Element %d : ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Enter integer to search : ");
    scanf("%d", &s);

    int result = binary_search(arr, 0, n - 1, s);

    // Displaying the array
    printf("[");
    for (int i = 0; i < n; i++) 
    {
        if (i == n - 1)
            printf("%d", arr[i]);
        else
            printf("%d, ", arr[i]);
    }
    printf("]\n");

    if (result != -1)
        printf("%d found at position : %d\n", s, result);
    else
        printf("%d not found\n", s);

    return 0;
}
