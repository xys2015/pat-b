#include <stdio.h>
#include <stdlib.h>
#define LEN 100010
int compare (const void *a, const void *b);
int main (void) {
    int day;
    int dist[LEN];
    int i;
    int e = 0; // 满足有E天骑车超过E英里的最大整数E
    int flag = 0;

    scanf("%d", &day);
    for (i = 1; i <= day; i++) {
        scanf("%d", &dist[i]);
    }
    qsort(dist + 1, day, sizeof(int), compare);

    for (i = 1; i <= day; i++) {
        if (i < dist[i]) e++;
        else break;
    }
    printf("%d", e);
    return 0;
}

int compare (const void *a, const void *b) {
    int arg1 = *(int*)a;
    int arg2 = *(int*)b;
    return arg2 - arg1; // 递减排序
}
