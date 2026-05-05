#include <stdio.h>
#include <stdlib.h>

// insertion sort for each bucket
void insertionSort(float arr[], int size) {
    for (int i = 1; i < size; i++) {
        float key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    float arr[1000];

    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    // Step 1: create buckets
    float buckets[1000][1000];
    int bucketSize[1000] = {0};

    // Step 2: distribute elements
    for (int i = 0; i < n; i++) {
        int index = n * arr[i]; // bucket index
        buckets[index][bucketSize[index]++] = arr[i];
    }

    // Step 3: sort each bucket
    for (int i = 0; i < n; i++) {
        if (bucketSize[i] > 0) {
            insertionSort(buckets[i], bucketSize[i]);
        }
    }

    // Step 4: concatenate
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bucketSize[i]; j++) {
            arr[k++] = buckets[i][j];
        }
    }

    // print sorted array
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }

    return 0;
}