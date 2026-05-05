#include <stdio.h>
#include <stdlib.h>

// structure for intervals
typedef struct {
    int start, end;
} Interval;

// comparator for sorting by start time
int cmp(const void* a, const void* b) {
    Interval* x = (Interval*)a;
    Interval* y = (Interval*)b;
    return x->start - y->start;
}

// Min Heap for end times
int heap[1000];
int size = 0;

// swap
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// heapify up
void heapifyUp(int i) {
    while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// heapify down
void heapifyDown(int i) {
    int smallest = i;
    int l = 2*i + 1, r = 2*i + 2;

    if (l < size && heap[l] < heap[smallest])
        smallest = l;
    if (r < size && heap[r] < heap[smallest])
        smallest = r;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(smallest);
    }
}

// push
void push(int val) {
    heap[size] = val;
    heapifyUp(size);
    size++;
}

// pop min
void pop() {
    heap[0] = heap[--size];
    heapifyDown(0);
}

int main() {
    int n;
    scanf("%d", &n);

    Interval arr[1000];

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    // Step 1: sort by start time
    qsort(arr, n, sizeof(Interval), cmp);

    // Step 2: process meetings
    push(arr[0].end);

    for (int i = 1; i < n; i++) {
        // if room is free
        if (heap[0] <= arr[i].start) {
            pop();
        }
        // allocate room
        push(arr[i].end);
    }

    printf("%d\n", size); // number of rooms
    return 0;
}