//
// Created by Katya on 29.09.2026.
//
#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of elements (n): ");
    scanf("%d", &n);

    if (n < 3) {
        printf("Result: 0\n");
        return 0;
    }

    int arr[n];
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int count = 0;

    for (int i = 1; i < n - 1; i++) {
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
            count++;
        }
    }

    printf("Result: %d\n", count);
    return 0;
}