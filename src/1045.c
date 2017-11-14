#include <stdio.h>
#include <stdlib.h>

int compare (const void *a, const void *b);
int find (int start, int x, int sorted[], int len);

int main (void) {
    int n;
    int src[100010];
    int sorted[100010];
    int temp;
    int i;
    int j = 0;
    int k;
    int pos;
    int num = 0;
    int flag = 0;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &temp);
        src[i] = temp;
        sorted[i] = temp;
    }
    qsort(sorted, n, sizeof(int), compare);
    
    for (i = 0; i < n; i++) {
        if (src[i] == sorted[j]) {
            if (flag == 0) {
                num++;
            } else {
                sorted[j] = 0;
            }
            flag = 0;
            for (k = j + 1; k < n; k++) {
                if (sorted[k] != 0) {
                    j = k;
                    break;
                }
            }
        } else {
            flag = 1;
            pos = find(j, src[i], sorted, n);
            sorted[pos] = 0;
            // src[i] = 0;
        }
    }

    printf("%d\n", num);
    for (i = 0; i < n; i++) {
        if (sorted[i] != 0) {
            printf("%d ", sorted[i]);
        }
    }
/*
9
4 2 3 6 8 1 9 5 10
*/
    return 0;
}

int compare (const void *a, const void *b) {
    int arg1 = *(int*)a;
    int arg2 = *(int*)b;
    return arg1 - arg2;
}

// 从start开始找x
// 返回x的下标
int find (int start, int x, int sorted[], int len) {
    int i;
    for (i = start; i < len; i++) {
        if (sorted[i] == x) return i;
    }
}
