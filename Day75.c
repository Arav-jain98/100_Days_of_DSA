#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// simple hashmap using arrays (since constraints small)
int main() {
    int arr[MAX];
    int n;

    // input
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int prefixSum = 0;
    int maxLen = 0;

    // map: sum → first index
    int sumIndex[2001]; // offset for negative sums
    for (int i = 0; i < 2001; i++) sumIndex[i] = -2;

    int offset = 1000;
    sumIndex[offset] = -1; // sum = 0 at index -1

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        int key = prefixSum + offset;

        if (sumIndex[key] != -2) {
            int len = i - sumIndex[key];
            if (len > maxLen) {
                maxLen = len;
            }
        } else {
            sumIndex[key] = i; // store first occurrence
        }
    }

    printf("%d\n", maxLen);

    return 0;
}