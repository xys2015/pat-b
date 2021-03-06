#include <stdio.h>
#include <stdlib.h>

#define LEN 1010
int isTol (int arr[][LEN], int i, int j, int n, int m, int tol);

int repeat[1 << 24] = {0}; // = 2^24 = 16777216
int arr[LEN][LEN];


int main (void) {
    int m; // 列
    int n; // 行
    int tol;
    int x; // 列, 对应m
    int y; // 行, 对应n
    int color;
    int count = 0;
    int i;
    int j;

    scanf("%d %d %d", &m, &n, &tol);
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            scanf("%d", &arr[i][j]);
            repeat[arr[i][j]]++;
        }
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            // 先确定该点独一无二
            if (repeat[arr[i][j]] == 1) {
                // 再确定满足色差超过tol的条件
                if (isTol(arr, i, j, n, m, tol) == 1) {
                    x = j;
                    y = i;
                    // printf("i:%d j:%d\n", i, j);
                    color = arr[i][j];
                    count++;
                    if (count == 2) break;
                }
            }
        }
        if (count == 2) break;
    }

    if (count == 0) {
        printf("Not Exist\n");
    } else if (count == 1) {
        printf("(%d, %d): %d\n", x, y, color);
    } else if (count == 2) {
        printf("Not Unique\n");
    }

    return 0;
}

// 是返回1, 不是返回0
// i行 j列 n最大行 m最大列
int isTol (int arr[][LEN], int i, int j, int n, int m, int tol) {
    // 从左上角开始
    // n-1,m-1  n-1,m  n-1,m+1  n,m+1  n+1,m+1  n+1,m  n+1,m-1  n,m-1
    if (
        (/* (i - 1 < 0 &&  j - 1 < 0) ? 1 :  */(abs(arr[i][j] - arr[i-1][j-1]) > tol)) && // 左上
        (/* (i - 1 < 0) ? 1 :  */(abs(arr[i][j] - arr[i-1][j]) > tol)) &&   // 上
        (/* (i - 1 < 0 && j + 1 > m) ? 1 :  */(abs(arr[i][j] - arr[i-1][j+1]) > tol)) && // 右上
        (/* (j + 1 > m) ? 1 :  */(abs(arr[i][j] - arr[i][j+1]) > tol)) &&   // 右
        (/* (i + 1 > n && j + 1 > m) ? 1 :  */(abs(arr[i][j] - arr[i+1][j+1]) > tol)) && // 右下
        (/* (i + 1 > n) ? 1 :  */(abs(arr[i][j] - arr[i+1][j]) > tol)) &&   // 下
        (/* (i + 1 > n && j - 1 < 0) ? 1 :  */(abs(arr[i][j] - arr[i+1][j-1]) > tol)) && // 左下
        (/* (j - 1 < 0) ? 1 :  */(abs(arr[i][j] - arr[i][j-1]) > tol))      // 左
    ) {
        return 1;
    } else {
        return 0;
    }
}
