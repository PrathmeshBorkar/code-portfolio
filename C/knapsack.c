#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100
#define MAX_CAPACITY 1000

struct Item {
    int id;
    int weight;
    int value;
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

void knapsack(struct Item items[], int n, int capacity) {
    // dp[i][w] stores maximum value with i items and capacity w
    static int dp[MAX_ITEMS + 1][MAX_CAPACITY + 1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (items[i - 1].weight <= w) {
                dp[i][w] = max(items[i - 1].value + dp[i - 1][w - items[i - 1].weight], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // Backtracking to find selected items
    int totalProfit = dp[n][capacity];
    int res = totalProfit;
    int w = capacity;
    struct Item selected[MAX_ITEMS];
    int count = 0;

    for (int i = n; i > 0 && res > 0; i--) {
        if (res != dp[i - 1][w]) {
            selected[count++] = items[i - 1];
            res -= items[i - 1].value;
            w -= items[i - 1].weight;
        }
    }

    // Displaying the result
    int totalWeight = 0;
    printf("\n--- 0/1 Knapsack Solution (Dynamic Programming) ---\n");
    printf("Item \t\t Weight \t Value\n");
    printf("-----------------------------------------\n");
    for (int i = count - 1; i >= 0; i--) {
        printf("Item %d \t\t %d \t\t %d\n", selected[i].id, selected[i].weight, selected[i].value);
        totalWeight += selected[i].weight;
    }
    printf("-----------------------------------------\n");
    printf("Total Weight Used: %d / %d\n", totalWeight, capacity);
    printf("Total Value / Maximum Profit: %d\n", totalProfit);
}

int main() {
    int n, capacity;
    struct Item items[MAX_ITEMS];

    printf("Enter number of items (Max %d): ", MAX_ITEMS);
    scanf("%d", &n);

    printf("Enter knapsack capacity (Max %d): ", MAX_CAPACITY);
    scanf("%d", &capacity);

    if (n <= 0 || n > MAX_ITEMS || capacity <= 0 || capacity > MAX_CAPACITY) {
        printf("Invalid input constraints!\n");
        return 1;
    }

    printf("\nEnter items (weight value):\n");
    for (int i = 0; i < n; i++) {
        items[i].id = i + 1;
        printf("Item %d (weight value): ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].value);
    }

    knapsack(items, n, capacity);

    return 0;
}
