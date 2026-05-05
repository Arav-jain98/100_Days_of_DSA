#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// adjacency list node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* adj[MAX];
int visited[MAX];
int recStack[MAX];
int n;

// add edge (directed)
void addEdge(int u, int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = v;
    newNode->next = adj[u];
    adj[u] = newNode;
}

// DFS for cycle detection
int dfs(int node) {
    visited[node] = 1;
    recStack[node] = 1;

    Node* temp = adj[node];
    while (temp != NULL) {
        int neighbor = temp->data;

        if (!visited[neighbor]) {
            if (dfs(neighbor))
                return 1;
        }
        else if (recStack[neighbor]) {
            return 1; // cycle detected
        }

        temp = temp->next;
    }

    recStack[node] = 0; // backtrack
    return 0;
}

int hasCycle() {
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i))
                return 1;
        }
    }
    return 0;
}

int main() {
    int edges, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
        recStack[i] = 0;
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter directed edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    if (hasCycle())
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}