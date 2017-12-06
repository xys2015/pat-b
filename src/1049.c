#include <stdio.h>

int main (void) {
    int n;
    double sum = 0.0;
    double tmp;
    int i;
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%lf", &tmp);
        sum += tmp * (double)(n - i + 1) * (double)(i);
    }
    printf("%.2f\n", sum);

    return 0;
}
