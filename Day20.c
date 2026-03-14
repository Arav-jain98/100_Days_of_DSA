#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

typedef struct {
    long long key;
    int value;
} Hash;

Hash table[MAX];

int hashFunc(long long key) {
    return abs(key) % MAX;
}

int main() {
    int n;
    scanf("%d", &n);

    long long arr[n];
    for(int i = 0; i < n; i++)
        scanf("%lld", &arr[i]);

    long long sum = 0;
    int count = 0;

    for(int i = 0; i < MAX; i++) {
        table[i].key = -1;
        table[i].value = 0;
    }

    int idx = hashFunc(0);
    table[idx].key = 0;
    table[idx].value = 1;

    for(int i = 0; i < n; i++) {
        sum += arr[i];
        idx = hashFunc(sum);

        if(table[idx].key == sum)
            count += table[idx].value;

        if(table[idx].key == -1)
            table[idx].key = sum;

        table[idx].value++;
    }

    printf("%d\n", count);

    return 0;
}