#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EMPTY -1

int* table;
int m;

// insert using quadratic probing
void insert(int key) {
    for (int i = 0; i < m; i++) {
        int index = (key % m + i * i) % m;

        if (table[index] == EMPTY) {
            table[index] = key;
            return;
        }
    }
    printf("Hash table is full\n");
}

// search using quadratic probing
void search(int key) {
    for (int i = 0; i < m; i++) {
        int index = (key % m + i * i) % m;

        if (table[index] == EMPTY) {
            printf("NOT FOUND\n");
            return;
        }

        if (table[index] == key) {
            printf("FOUND\n");
            return;
        }
    }
    printf("NOT FOUND\n");
}

int main() {
    int q;
    scanf("%d", &m);   // table size
    scanf("%d", &q);   // number of operations

    table = (int*)malloc(m * sizeof(int));

    // initialize
    for (int i = 0; i < m; i++) {
        table[i] = EMPTY;
    }

    char op[10];
    int key;

    for (int i = 0; i < q; i++) {
        scanf("%s %d", op, &key);

        if (strcmp(op, "INSERT") == 0) {
            insert(key);
        } else if (strcmp(op, "SEARCH") == 0) {
            search(key);
        }
    }

    free(table);
    return 0;
}