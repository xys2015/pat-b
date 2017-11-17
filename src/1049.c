#include <stdio.h>

int main (void) {
    int n;
    long double cur;
    long double tail = 0.0;
    long double sum = 0.0;
    int i;

    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%Lf", &cur);
        tail += i * cur;
        sum += tail;
    }
    printf("%.2Lf", sum);

    return 0;
}
