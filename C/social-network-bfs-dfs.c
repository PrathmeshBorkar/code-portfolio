#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_USERS 10000

struct Node {
    int vertex;
    struct Node* next;
};

static struct Node* adjLists[MAX_USERS];
static int visited[MAX_USERS];
static int queue[MAX_USERS];

struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = adjLists[src];
    adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = adjLists[dest];
    adjLists[dest] = newNode;
}

void resetVisited(int n) {
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }
}

void DFS(int vertex) {
    visited[vertex] = 1;
    struct Node* temp = adjLists[vertex];

    while (temp != NULL) {
        int connectedVertex = temp->vertex;
        if (visited[connectedVertex] == 0) {
            DFS(connectedVertex);
        }
        temp = temp->next;
    }
}

void BFS(int startVertex, int totalUsers) {
    int front = 0, rear = 0;

    visited[startVertex] = 1;
    queue[rear++] = startVertex;

    while (front < rear) {
        int currentVertex = queue[front++];
        struct Node* temp = adjLists[currentVertex];

        while (temp != NULL) {
            int adjVertex = temp->vertex;
            if (visited[adjVertex] == 0) {
                visited[adjVertex] = 1;
                queue[rear++] = adjVertex;
            }
            temp = temp->next;
        }
    }
}

int main() {
    int totalUsers, friendships;
    clock_t start, end;
    double total_time;

    printf("Enter total number of users (Max %d): ", MAX_USERS);
    scanf("%d", &totalUsers);

    printf("Enter total number of random friendships to generate: ");
    scanf("%d", &friendships);

    for (int i = 0; i < totalUsers; i++) {
        adjLists[i] = NULL;
    }

    srand(time(0));

    for (int i = 0; i < friendships; i++) {
        int u1 = rand() % totalUsers;
        int u2 = rand() % totalUsers;
        if (u1 != u2) {
            addEdge(u1, u2);
        }
    }

    printf("\nGraph created with %d users and ~%d connections.\n\n", totalUsers, friendships);

    resetVisited(totalUsers);
    start = clock();
    DFS(0);
    end = clock();
    total_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("DFS Traversal Time: %f seconds\n", total_time);

    resetVisited(totalUsers);
    start = clock();
    BFS(0, totalUsers);
    end = clock();
    total_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("BFS Traversal Time: %f seconds\n", total_time);

    return 0;
}