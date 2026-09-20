#include <stdio.h>
#include <stdlib.h>

#define MAX_EDGES 1000
#define MAX_VERTICES 100

struct Edge {
    int src;
    int dest;
    int weight;
};

struct Graph {
    int V, E;
    struct Edge edges[MAX_EDGES];
};

// Path compression
int findParent(int parent[], int i) {
    if (parent[i] == -1)
        return i;
    return parent[i] = findParent(parent, parent[i]);
}

void unionSet(int parent[], int x, int y) {
    int xset = findParent(parent, x);
    int yset = findParent(parent, y);
    if (xset != yset) {
        parent[xset] = yset;
    }
}

int compareEdges(const void* a, const void* b) {
    struct Edge* a1 = (struct Edge*)a;
    struct Edge* b1 = (struct Edge*)b;
    return a1->weight - b1->weight;
}

void kruskalMST(struct Graph* graph) {
    int V = graph->V;
    int E = graph->E;
    struct Edge result[MAX_VERTICES];
    int e = 0;
    int i = 0;

    qsort(graph->edges, E, sizeof(graph->edges[0]), compareEdges);

    int parent[MAX_VERTICES];
    for (int v = 0; v < V; v++) {
        parent[v] = -1;
    }

    while (e < V - 1 && i < E) {
        struct Edge nextEdge = graph->edges[i++];

        int x = findParent(parent, nextEdge.src);
        int y = findParent(parent, nextEdge.dest);

        if (x != y) {
            result[e++] = nextEdge;
            unionSet(parent, x, y);
        }
    }

    // Displaying the MST
    int totalWeight = 0;
    printf("\n--- Minimum Spanning Tree (Kruskal's Algorithm) ---\n");
    printf("Edge \t\t Weight\n");
    printf("-------------------------\n");
    for (i = 0; i < e; i++) {
        printf("%d - %d \t\t %d\n", result[i].src, result[i].dest, result[i].weight);
        totalWeight += result[i].weight;
    }
    printf("-------------------------\n");
    printf("Total Weight of MST: %d\n", totalWeight);
}

int main() {
    struct Graph graph;

    printf("Enter number of vertices (Max %d): ", MAX_VERTICES);
    scanf("%d", &graph.V);

    printf("Enter number of edges (Max %d): ", MAX_EDGES);
    scanf("%d", &graph.E);

    if (graph.V <= 0 || graph.V > MAX_VERTICES || graph.E <= 0 || graph.E > MAX_EDGES) {
        printf("Invalid input constraints!\n");
        return 1;
    }

    printf("\nEnter edges (source destination weight):\n");
    for (int i = 0; i < graph.E; i++) {
        printf("Edge %d (src dest weight): ", i + 1);
        scanf("%d %d %d", &graph.edges[i].src, &graph.edges[i].dest, &graph.edges[i].weight);
    }

    kruskalMST(&graph);

    return 0;
}
