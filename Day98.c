#include <stdio.h>
#include <stdlib.h>

// interval structure
typedef struct {
    int start, end;
} Interval;

// comparator (sort by start)
int cmp(const void* a, const void* b) {
    Interval* x = (Interval*)a;
    Interval* y = (Interval*)b;
    return x->start - y->start;
}

int main() {
    int n;
    scanf("%d", &n);

    Interval arr[1000];

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    // Step 1: sort
    qsort(arr, n, sizeof(Interval), cmp);

    Interval result[1000];
    int index = 0;

    result[0] = arr[0];

    // Step 2: merge
    for (int i = 1; i < n; i++) {
        if (arr[i].start <= result[index].end) {
            // overlap → merge
            if (arr[i].end > result[index].end) {
                result[index].end = arr[i].end;
            }
        } else {
            // no overlap → new interval
            result[++index] = arr[i];
        }
    }

    // Step 3: print result
    for (int i = 0; i <= index; i++) {
        printf("%d %d\n", result[i].start, result[i].end);
    }

    return 0;
}