#include <stdio.h>

int main() {
    int m, n;
    
    // Read matrix dimensions
    scanf("%d %d", &m, &n);
    
    int matrix[m][n];
    
    // Read matrix elements
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    // A symmetric matrix must be square
    if (m != n) {
        printf("Not a Symmetric Matrix");
        return 0;
    }
    
    // Check symmetry
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                printf("Not a Symmetric Matrix");
                return 0;
            }
        }
    }
    
    printf("Symmetric Matrix");
    
    return 0;
}