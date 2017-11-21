#include <stdio.h>
#include <math.h>

int main (void) {
    int n;
    int a;
    int b;
    int max = 0; // 最大平方和 
    int tmp;     // 临时存放平方和
    int i;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d %d", &a, &b);
        tmp = a * a + b * b;
        if (tmp > max) max = tmp;
    }
    printf("%.2f", sqrt(max));

    return 0;
}
