#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10000

typedef struct {
    int arr[MAX];
    int front;
    int rear;
} Deque;

// Initialize deque
void init(Deque* dq) {
    dq->front = 0;
    dq->rear = -1;
}

// Check if empty
bool empty(Deque* dq) {
    return dq->front > dq->rear;
}

// Size
int size(Deque* dq) {
    if (empty(dq)) return 0;
    return dq->rear - dq->front + 1;
}

// Push back
void push_back(Deque* dq, int value) {
    dq->arr[++dq->rear] = value;
}

// Push front
void push_front(Deque* dq, int value) {
    dq->arr[--dq->front] = value;
}

// Pop front
void pop_front(Deque* dq) {
    if (!empty(dq)) dq->front++;
}

// Pop back
void pop_back(Deque* dq) {
    if (!empty(dq)) dq->rear--;
}

// Get front
int front(Deque* dq) {
    return dq->arr[dq->front];
}

// Get back
int back(Deque* dq) {
    return dq->arr[dq->rear];
}