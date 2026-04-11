#include <stdio.h>
#include <stdlib.h>

// Stack Structure
typedef struct {
    int *arr;
    int top;
} Stack;

// Queue Structure
typedef struct {
    int *arr;
    int front;
    int rear;
    int size;
} Queue;

// --- Stack Functions ---
void push(Stack *s, int val) {
    s->arr[++(s->top)] = val;
}

int pop(Stack *s) {
    return s->arr[(s->top)--];
}

// --- Queue Functions ---
void enqueue(Queue *q, int val) {
    q->arr[++(q->rear)] = val;
}

int dequeue(Queue *q) {
    return q->arr[(q->front)++];
}

int main() {
    int N;
    if (scanf("%d", &N) != 1) return 0;

    // Allocate memory for Stack and Queue
    Stack s;
    s.arr = (int *)malloc(sizeof(int) * N);
    s.top = -1;

    Queue q;
    q.arr = (int *)malloc(sizeof(int) * N);
    q.front = 0;
    q.rear = -1;

    // Input elements into Queue
    for (int i = 0; i < N; i++) {
        int temp;
        scanf("%d", &temp);
        enqueue(&q, temp);
    }

    // Step 1: Move all elements from Queue to Stack
    for (int i = 0; i < N; i++) {
        push(&s, dequeue(&q));
    }

    // Step 2: Move all elements from Stack back to Queue
    // We reset the queue pointers to reuse the same array
    q.front = 0;
    q.rear = -1;
    for (int i = 0; i < N; i++) {
        enqueue(&q, pop(&s));
    }

    // Output the reversed Queue
    for (int i = 0; i < N; i++) {
        printf("%d%s", q.arr[i], (i == N - 1) ? "" : " ");
    }
    printf("\n");

    // Clean up
    free(s.arr);
    free(q.arr);

    return 0;
}