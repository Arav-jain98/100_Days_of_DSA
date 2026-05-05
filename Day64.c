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
int n;

// queue
int queue[MAX];
int front = 0, rear = 0;

// enqueue
void enqueue(int x) {
    queue[rear++] = x;
}

// dequeue
int dequeue() {
    return queue[front++];
}

// check empty
int isEmpty() {
    return front == rear;
}

// add edge (undirected)
void addEdge(int u, int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = v;
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = (Node*)malloc(sizeof(Node));
    newNode->data = u;
    newNode->next = adj[v];
    adj[v] = newNode;
}

// BFS function
void bfs(int start) {
    enqueue(start);
    visited[start] = 1;

    while (!isEmpty()) {
        int curr = dequeue();
        printf("%d ", curr);

        Node* temp = adj[curr];
        while (temp != NULL) {
            if (!visited[temp->data]) {
                enqueue(temp->data);
                visited[temp->data] = 1;
            }
            temp = temp->next;
        }
    }
}

int main() {
    int edges, u, v, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // initialize
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("BFS Traversal: ");
    bfs(start);

    return 0;
}