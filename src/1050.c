/*
本题要求将给定的N个正整数按非递增(递减)的顺序，填入“螺旋矩阵”。所谓“螺旋矩阵”，是指从左上角第1个格子开始，按顺时针螺旋方向填充。要求矩阵的规模为 m行n列，
满足条件：m*n等于N；m>=n； 行>=列
且m-n取所有可能值中的最小值。

输入格式：

输入在第1行中给出一个正整数N，第2行给出N个待填充的正整数。所有数字不超过10^4，相邻数字以空格分隔。

输出格式：

输出螺旋矩阵。每行n个数字，共m行。相邻数字以1个空格分隔，行末不得有多余空格。

输入样例：
12
37 76 20 98 76 42 53 95 60 81 58 93

0  1  2  3  4  5  6  7  8  9  10 11
98 95 93 81 76 76 60 58 53 42 37 20
98 95 93 42 37 81 53 20 76 58 60 76
0  1  2  9  10 3  8  11 4  7  6  5                    
0  1  2  3  4  5  6  7  8  9  10 11
输出样例： m=4行, n=3列
98 95 93
42 37 81
53 20 76
58 60 76
*/
#include <stdio.h>

int main (void) {
    int n;
    int hang;
    int lie;
    int rhang;
    int rlie;
    int min;
    int src[10010];
    int matrix[10010];
    int pos;
    int temp;
    int i;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", src[i]);
    }
    matrix = src[0]; // 起始位置
    src[0] = 0; // 标记起点为0
    rhang = n;
    rlie = 1;
    min = n - 1;
    for (i = 1; i <= n / 2; i++) {
        if (n % i == 0) {
            hang = n / i;
            lie = i;
            if (hang < lie) { // 交换
                temp = hang;
                hang = lie;
                lie = temp;
            }
            if (min > hang - lie) {
                min = hang - lie;
                rhang = hang;
                rlie = lie;
            }
        }
    }
    // printf("rhang: %d\n", rhang);
    // printf("rlie: %d\n", rlie);
    

    return 0;
}

int move (int src[], int now, int lie) {
    int next; // 移动后的位置
    if (src[now + 1] != 0) {
        src[now] = 0;
        next = now + 1;
    } else if(src[now + lie] != 0) {
        src[now] = 0;
        next = now + lie;
    } else if (src[now - 1] != 0) {
        src[now] = 0;
        next = now - 1;
    } else if (src[now - lie] != 0) {
        src[now] = 0;
        next = now - lie;
    }
    return next;
}