#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long fibonacci(int n) {
    long long a = 0, b = 1, c;
    
    if (n < 0) {
        printf("Incorrect input\n");
        return -1;
    } else if (n == 0) {
        return 0;
    } else if (n == 1) {
        return b;
    } else {
        for (int i = 1; i < n; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <number>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    clock_t start_time = clock();
    long long result = fibonacci(n);
    clock_t end_time = clock();
    double time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

    printf("%d,%f\n", n, time_used);
    return 0;
}