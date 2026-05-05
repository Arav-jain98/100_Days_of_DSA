#include <stdio.h>

// check if we can paint within maxTime
int canPaint(int boards[], int n, int k, int maxTime) {
    int painters = 1;
    int currTime = 0;

    for (int i = 0; i < n; i++) {
        if (currTime + boards[i] > maxTime) {
            painters++;
            currTime = boards[i];

            if (painters > k) return 0;
        } else {
            currTime += boards[i];
        }
    }

    return 1;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int boards[1000];
    int sum = 0, maxVal = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &boards[i]);
        sum += boards[i];
        if (boards[i] > maxVal) maxVal = boards[i];
    }

    int left = maxVal;
    int right = sum;
    int ans = sum;

    // binary search
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (canPaint(boards, n, k, mid)) {
            ans = mid;
            right = mid - 1; // try smaller time
        } else {
            left = mid + 1;
        }
    }

    printf("%d\n", ans);
    return 0;
}