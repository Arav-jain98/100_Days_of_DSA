#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

// adjacency list node
typedef struct Node {
    int v, w;
    struct Node* next;
} Node;

Node* adj[MAX];
int n, m;

// Min Heap Node
typedef struct {
    int node, dist;
} HeapNode;

HeapNode heap[MAX * MAX];
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
    int l = 2*i + 1, r = 2*i + 2;

    if (l < heapSize && heap[l].dist < heap[smallest].dist)
        smallest = l;
    if (r < heapSize && heap[r].dist < heap[smallest].dist)
        smallest = r;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(smallest);
    }
}

// push
void push(int node, int dist) {
    heap[heapSize].node = node;
    heap[heapSize].dist = dist;
    heapifyUp(heapSize);
    heapSize++;
}

// pop
HeapNode pop() {
    HeapNode root = heap[0];
    heap[0] = heap[--heapSize];
    heapifyDown(0);
    return root;
}

// add edge
void addEdge(int u, int v, int w) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->v = v;
    newNode->w = w;
    newNode->next = adj[u];
    adj[u] = newNode;
}

// Dijkstra
void dijkstra(int src) {
    int dist[MAX];
    int visited[MAX] = {0};

    for (int i = 1; i <= n; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;
    push(src, 0);

    while (heapSize > 0) {
        HeapNode curr = pop();
        int u = curr.node;

        if (visited[u]) continue;
        visited[u] = 1;

        Node* temp = adj[u];
        while (temp) {
            int v = temp->v;
            int w = temp->w;

            if (!visited[v] && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(v, dist[v]);
            }

            temp = temp->next;
        }
    }

    // print result
    for (int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }
    printf("\n");
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++)
        adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
        addEdge(v, u, w); // undirected
    }

    int src;
    scanf("%d", &src);

    dijkstra(src);

    return 0;
}