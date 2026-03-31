#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int *queue = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &queue[i]);
    }

    int m;
    scanf("%d", &m);

    int front = 0;
    int rear = n - 1;
    int size = n;

    // Perform m dequeue operations
    for (int i = 0; i < m; i++) {
        if (size > 0) {
            front = (front + 1) % n;
            size--;
        }
    }

    // Print remaining elements in circular order
    for (int i = 0; i < size; i++) {
        int index = (front + i) % n;
        printf("%d ", queue[index]);
    }

    free(queue);
    return 0;
}