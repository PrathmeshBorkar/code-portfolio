#include <stdio.h>

void main()
{
    int n, i;
    printf("Enter size of array : ");
    scanf("%d", &n);

    int arr[n];
    
    for (i = 0; i < n; i++)
    {
        int a;
        printf("Element %d : ", i + 1);
        scanf("%d", &a);
        arr[i] = a;
    }

    int s;
    printf("Enter integer to search : ");
    scanf("%d", &s);

    int mid, low = 0, high = n - 1, flag = 0;

    while (low <= high)
    {
        mid = (low + high) / 2;
            
        if (arr[mid] == s)
        {   
            flag = 1;
            break;
        }
        else if (arr[mid] < s)
            low = mid + 1;
        else
            high = mid - 1;
    }

    // Displaying the array
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);

        if (i != n - 1)
            printf(", ");
    }
    printf("]\n");

    if (flag == 1)
        printf("%d found at position : %d", s, mid);
    else
        printf("%d not found", s);
}