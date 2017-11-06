#include <stdio.h>

int main (void) {
    float CLK_TCK = 100.0;
    int c1;
    int c2;
    int source;
    int h = 0;
    int m = 0;
    int s = 0;

    scanf("%d %d", &c1, &c2);
    source = (int)((c2 - c1) / CLK_TCK + 0.5);
    h = source / 3600;
    m = (source - h * 3600) / 60;
    s = source - h * 3600 - m * 60;
    printf("%02d:%02d:%02d\n", h, m, s);

    return 0;
}