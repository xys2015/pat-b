#include <stdio.h>
#include <stdlib.h>
// 绳子必须用完!!! 绳子必须用完!!! 绳子必须用完!!!
#define LEN 10010

int compare (const void *a, const void *b);

int main (void) {
    int n;
    int length[LEN];
    int sum;
    int i;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &length[i]);
    }
    qsort(length, n, sizeof(int), compare);
    sum = length[0];
    for (i = 1; i < n; i++) {
        sum = (sum + length[i]) / 2;
    }
    printf("%d", sum);

    return 0;
}

int compare (const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}
