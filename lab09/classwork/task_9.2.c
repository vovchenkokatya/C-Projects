//
// Created by Katya on 25.10.2026.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX_ARRAY_SIZE 100

int input_array(int *arr) {
    int n = 0;
    int x;

    while (n < MAX_ARRAY_SIZE) {
        printf("Enter element %d (0 to stop): ", n + 1);
        if (scanf("%d", &x) != 1 || x == 0) {
            break;
        }
        arr[n] = x;
        n++;
    }
    return n;
}

bool is_square(int x) {
    if (x < 0) {
        return false;
    }
    int root = (int)sqrt(x);
    return (long long)root * root == x;
}

bool is_cube(int x) {
    int root = (int)round(cbrt(x));
    return (long long)root * root * root == x;
}

int main(void) {
    int *arr = (int *)malloc(MAX_ARRAY_SIZE * sizeof(int));
    if (arr == NULL) {
        return 1;
    }

    int n = input_array(arr);
    int squares = 0;
    int cubes = 0;

    for (int i = 0; i < n; i++) {
        if (is_square(arr[i])) {
            squares++;
        }
        if (is_cube(arr[i])) {
            cubes++;
        }
    }

    printf("Perfect squares: %d\n", squares);
    printf("Perfect cubes: %d\n", cubes);

    free(arr);
    return 0;
}