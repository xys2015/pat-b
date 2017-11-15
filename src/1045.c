#include <stdio.h>

int main (void) {
    int n;
    int arr[100010];
    int lmax[100010];
    int rmin[100010];
    int count = 0;
    int max;
    int min;
    int i;
    char ch = ' ';

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // 从左边开始, 一步步找当前数左边的最大数
    max = arr[0]; // 初始最大数
    for (i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        lmax[i] = max;
    }
    // 从右边开始, 一步步找当前数右边的最小数
    min = arr[n - 1]; // 初始最小数
    for (i = n - 1; i >= 0; i--) {
        if (arr[i] < min) {
            min = arr[i];
        }
        rmin[i] = min;
    }

    for (i = 0; i < n; i++) {
        if (arr[i] == lmax[i] && arr[i] == rmin[i]) {
            count++;
        } else {
            arr[i] = 0;
        }
    }
    printf("%d\n", count);
    for (i = 0; i < n && count != 0; i++) {
        if (count == 1) ch = '\0';
        if (arr[i] != 0) {
            printf("%d%c", arr[i], ch);
            count--;
        }
    }
    printf("\n");

    return 0;
}
