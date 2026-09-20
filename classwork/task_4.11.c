#include <stdio.h>
#include <math.h>

int main() {
    int a;
    int sum = 0;
    double harm_sum = 0.0;
    int k = 0;

    do {
        printf("Enter a number (0 to exit): ");
        scanf("%d", &a);

        if (a != 0) {
            sum += a;
            harm_sum += 1.0 / a;
            k++;
        }
    } while (a != 0);

    if (k != 0) {
        printf("Average of entered nums: %lf\n", (double)sum / k);
        printf("Harmonic mean of entered nums: %lf\n", (double)k / harm_sum);
    }

    return 0;
}