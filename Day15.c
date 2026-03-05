#include <stdio.h>

int main() {
    int m, n;
    int a[100][100];
    int sum = 0;

    scanf("%d %d", &m, &n);

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) {
                sum += a[i][j];
            }
        }
    }

    printf("%d", sum);

    return 0;
}