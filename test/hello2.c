#include <stdio.h>

int main (void) {
    int n;
    double inc = 0.0;
    double sum = 0.0;
    double tmp;
    int i;

    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%lf", &tmp);
        inc += i * tmp;
        sum += inc;
    }
    printf("%.2f", sum);

    return 0;
}
