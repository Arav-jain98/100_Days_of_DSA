#include <stdio.h>

// check if allocation is possible
int canAllocate(int arr[], int n, int m, int maxPages) {
    int students = 1;
    int pages = 0;

    for (int i = 0; i < n; i++) {
        if (pages + arr[i] > maxPages) {
            students++;
            pages = arr[i];

            if (students > m) return 0;
        } else {
            pages += arr[i];
        }
    }
    return 1;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int arr[1000];
    int sum = 0, maxVal = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
        if (arr[i] > maxVal) maxVal = arr[i];
    }

    // edge case
    if (m > n) {
        printf("-1\n");
        return 0;
    }

    int left = maxVal;
    int right = sum;
    int ans = sum;

    // binary search
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (canAllocate(arr, n, m, mid)) {
            ans = mid;
            right = mid - 1;  // try smaller max
        } else {
            left = mid + 1;
        }
    }

    printf("%d\n", ans);
    return 0;
}