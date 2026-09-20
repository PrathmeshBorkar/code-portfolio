#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100
#define INF 999999

int minKey(int key[], bool mstSet[], int n) {
    int min = INF, min_index = -1;

    for (int v = 0; v < n; v++) {
        if (mstSet[v] == false && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}

void primMST(int graph[MAX][MAX], int n) {
    int parent[MAX];
    int key[MAX];
    bool mstSet[MAX];

    for (int i = 0; i < n; i++) {
        key[i] = INF;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < n - 1; count++) {
        int u = minKey(key, mstSet, n);

        if (u == -1) break;

        mstSet[u] = true;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] && graph[u][v] != INF && mstSet[v] == false && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Displaying the MST
    int totalWeight = 0;
    printf("\n--- Minimum Spanning Tree (Prim's Algorithm) ---\n");
    printf("Edge \t\t Weight\n");
    printf("-------------------------\n");
    for (int i = 1; i < n; i++) {
        if (parent[i] != -1) {
            printf("%d - %d \t\t %d\n", parent[i], i, graph[i][parent[i]]);
            totalWeight += graph[i][parent[i]];
        }
    }
    printf("-------------------------\n");
    printf("Total Weight of MST: %d\n", totalWeight);
}

int main() {
    int n;

    printf("Enter number of vertices (Max %d): ", MAX);
    scanf("%d", &n);

    if (n <= 0 || n > MAX) {
        printf("Invalid number of vertices!\n");
        return 1;
    }

    int graph[MAX][MAX];

    printf("\nEnter adjacency matrix for the graph (Enter 0 for self-loops and 0 or %d for no edge):\n", INF);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
            if (i == j) {
                graph[i][j] = 0;
            } else if (graph[i][j] == 0) {
                graph[i][j] = INF;
            }
        }
    }

    primMST(graph, n);

    return 0;
}
