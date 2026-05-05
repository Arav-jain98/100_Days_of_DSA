#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pos;
    double time;
} Car;

// sort by position descending
int cmp(const void* a, const void* b) {
    Car* c1 = (Car*)a;
    Car* c2 = (Car*)b;
    return c2->pos - c1->pos;
}

int carFleet(int target, int position[], int speed[], int n) {
    Car cars[1000];

    // Step 1: compute time
    for (int i = 0; i < n; i++) {
        cars[i].pos = position[i];
        cars[i].time = (double)(target - position[i]) / speed[i];
    }

    // Step 2: sort by position (descending)
    qsort(cars, n, sizeof(Car), cmp);

    int fleets = 0;
    double lastTime = 0;

    // Step 3: process
    for (int i = 0; i < n; i++) {
        if (cars[i].time > lastTime) {
            fleets++;
            lastTime = cars[i].time;
        }
    }

    return fleets;
}

int main() {
    int n, target;
    scanf("%d %d", &n, &target);

    int position[1000], speed[1000];

    for (int i = 0; i < n; i++) scanf("%d", &position[i]);
    for (int i = 0; i < n; i++) scanf("%d", &speed[i]);

    int result = carFleet(target, position, speed, n);
    printf("%d\n", result);

    return 0;
}