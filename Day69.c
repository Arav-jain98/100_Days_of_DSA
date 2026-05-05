#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

// adjacency list node
typedef struct Node {
    int vertex, weight;
    struct Node* next;
} Node;

Node* adj[MAX];
int n;

// Min Heap Node
typedef struct {
    int vertex;
    int dist;
} HeapNode;

HeapNode heap[MAX];
int heapSize = 0;

// swap
void swap(HeapNode* a, HeapNode* b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// heapify up
void heapifyUp(int i) {
    while (i > 0 && heap[(i - 1) / 2].dist > heap[i].dist) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// heapify down
void heapifyDown(int i) {
    int smallest = i;
    int left = 2 * i + 1, right = 2 * i + 2;

    if (left < heapSize && heap[left].dist < heap[smallest].dist)
        smallest = left;
    if (right < heapSize && heap[right].dist < heap[smallest].dist)
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(smallest);
    }
}

// push into heap
void push(int v, int d) {
    heap[heapSize].vertex = v;
    heap[heapSize].dist = d;
    heapifyUp(heapSize);
    heapSize++;
}

// pop min
HeapNode pop() {
    HeapNode root = heap[0];
    heap[0] = heap[--heapSize];
    heapifyDown(0);
    return root;
}

// add edge
void addEdge(int u, int v, int w) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = adj[u];
    adj[u] = newNode;
}

// Dijkstra
void dijkstra(int src) {
    int dist[MAX];
    int visited[MAX] = {0};

    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;
    push(src, 0);

    while (heapSize > 0) {
        HeapNode curr = pop();
        int u = curr.vertex;

        if (visited[u]) continue;
        visited[u] = 1;

        Node* temp = adj[u];
        while (temp != NULL) {
            int v = temp->vertex;
            int w = temp->weight;

            if (!visited[v] && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(v, dist[v]);
            }

            temp = temp->next;
        }
    }

    // print result
    printf("Shortest distances from source %d:\n", src);
    for (int i = 0; i < n; i++) {
        printf("To %d = %d\n", i, dist[i]);
    }
}

int main() {
    int edges, u, v, w, src;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v w):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w); // directed
    }

    printf("Enter source: ");
    scanf("%d", &src);

    dijkstra(src);

    return 0;
}