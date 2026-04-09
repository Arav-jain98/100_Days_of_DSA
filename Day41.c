#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Queue structure
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// Initialize queue
void initQueue(Queue* q) {
    q->front = q->rear = NULL;
}

// Enqueue operation
void enqueue(Queue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }

    q->rear->next = newNode;
    q->rear = newNode;
}

// Dequeue operation
int dequeue(Queue* q) {
    if (q->front == NULL) {
        return -1;  // queue is empty
    }

    Node* temp = q->front;
    int value = temp->data;

    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    return value;
}

// Main function
int main() {
    int N;
    scanf("%d", &N);

    Queue q;
    initQueue(&q);

    for (int i = 0; i < N; i++) {
        char op[10];
        scanf("%s", op);

        if (strcmp(op, "enqueue") == 0) {
            int x;
            scanf("%d", &x);
            enqueue(&q, x);
        } 
        else if (strcmp(op, "dequeue") == 0) {
            printf("%d\n", dequeue(&q));
        }
    }

    return 0;
}