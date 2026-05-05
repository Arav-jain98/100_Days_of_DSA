#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// adjacency list node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* adj[MAX];
int indegree[MAX];
int n;

// add directed edge
void addEdge(int u, int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = v;
    newNode->next = adj[u];
    adj[u] = newNode;

    indegree[v]++;
}

// Kahn's Algorithm
void topoSort() {
    int queue[MAX];
    int front = 0, rear = 0;

    // Step 1: push nodes with indegree 0
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    int count = 0;

    printf("Topological Order: ");

    // Step 2: BFS
    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);
        count++;

        Node* temp = adj[node];
        while (temp != NULL) {
            int neighbor = temp->data;
            indegree[neighbor]--;

            if (indegree[neighbor] == 0) {
                queue[rear++] = neighbor;
            }

            temp = temp->next;
        }
    }

    // Step 3: cycle check
    if (count != n) {
        printf("\nCycle detected! Topological sort not possible.\n");
    }
}

int main() {
    int edges, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        indegree[i] = 0;
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter directed edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    topoSort();

    return 0;
}