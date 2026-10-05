//
// Created by Katya on 05.10.2026.
//
//
// Created by Katya on 05.10.2026.
//
//
// Created by Katya on 05.10.2026.
//
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int input_array(double arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("a[%d]= ", i + 1);
        int rez_input = scanf("%lf", &arr[i]);
        if (rez_input != 1) {
            printf("Invalid input\n");
            return i;
        }
    }
    return n;
}

void print_array(const double arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        printf("%g, ", arr[i]);
    }
    if (n > 0) {
        printf("%g\n", arr[n - 1]);
    }
}

double find_max_alternating(const double arr[], int n) {
    double max_val = -arr[0];

    for (int i = 1; i < n; i++) {
        // Для непарних індексів (i=1, 3... тобто k=2, 4): знак +
        // Для парних індексів (i=2, 4... тобто k=3, 5): знак -
        double current = (i % 2 == 0) ? -arr[i] : arr[i];
        if (current > max_val) {
            max_val = current;
        }
    }
    return max_val;
}

int main() {
    int n;
    printf("Enter n: ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX_SIZE) {
        printf("Invalid array size.\n");
        return 1;
    }

    double arr[MAX_SIZE];
    int count = input_array(arr, n);
    if (count != n) {
        return 1;
    }

    printf("The array is:\n");
    print_array(arr, n);

    double result = find_max_alternating(arr, n);
    printf("Result max(-a1, a2, -a3, ...): %g\n", result);

    return 0;
}