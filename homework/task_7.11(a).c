//
// Created by Katya on 05.10.2026.
//
#include <stdio.h>
#include <stdlib.h>

#define MAX_DEGREE 256

double chebyshev_value(int n, double x) {
    if (n == 0) {
        return 1.0;
    }
    if (n == 1) {
        return x;
    }

    double t_prev2 = 1.0; // T_0(x)
    double t_prev1 = x;   // T_1(x)
    double t_curr = 0.0;

    for (int i = 2; i <= n; i++) {
        t_curr = 2.0 * x * t_prev1 - t_prev2;
        t_prev2 = t_prev1;
        t_prev1 = t_curr;
    }

    return t_curr;
}

void print_chebyshev_coefficients(int n) {
    if (n < 0 || n >= MAX_DEGREE) {
        printf("Invalid degree\n");
        return;
    }

    double t_prev2[MAX_DEGREE] = {0.0};
    double t_prev1[MAX_DEGREE] = {0.0};
    double t_curr[MAX_DEGREE] = {0.0};

    // Базові випадки
    t_prev2[0] = 1.0; // T_0(x) = 1
    t_prev1[1] = 1.0; // T_1(x) = x

    if (n == 0) {
        for (int i = 0; i <= n; i++) {
            t_curr[i] = t_prev2[i];
        }
    } else if (n == 1) {
        for (int i = 0; i <= n; i++) {
            t_curr[i] = t_prev1[i];
        }
    } else {
        // Рекурентне співвідношення: T_k(x) = 2x * T_{k-1}(x) - T_{k-2}(x)
        for (int k = 2; k <= n; k++) {
            for (int i = 0; i <= k; i++) {
                t_curr[i] = 0.0;
            }
            // 2x * T_{k-1}(x) зсуває степені на 1 вгору
            for (int i = 0; i < k; i++) {
                t_curr[i + 1] += 2.0 * t_prev1[i];
            }
            // - T_{k-2}(x)
            for (int i = 0; i <= k - 2; i++) {
                t_curr[i] -= t_prev2[i];
            }

            // Оновлення для наступного кроку
            for (int i = 0; i <= k; i++) {
                t_prev2[i] = t_prev1[i];
                t_prev1[i] = t_curr[i];
            }
        }
    }

    printf("Coefficients of T_%d(x) from x^0 to x^%d:\n", n, n);
    for (int i = 0; i <= n; i++) {
        printf("a[%d] = %g\n", i, t_curr[i]);
    }
}

int main() {
    int n;
    printf("Enter n (0 <= n < %d): ", MAX_DEGREE);
    if (scanf("%d", &n) != 1 || n < 0 || n >= MAX_DEGREE) {
        printf("Wrong input. Please try again.\n");
        return 1;
    }

    double x;
    printf("Enter x: ");
    if (scanf("%lf", &x) != 1) {
        printf("Invalid input\n");
        return 1;
    }

    double val = chebyshev_value(n, x);
    printf("Value T_%d(%g) = %g\n\n", n, x, val);

    print_chebyshev_coefficients(n);

    return 0;
}