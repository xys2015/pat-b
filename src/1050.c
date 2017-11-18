#include <stdio.h>
#include <stdlib.h> // 定义qsort
#define LEN 10010

int compare (const void *a, const void *b);

int main (void) {
    int n;
    int height;   // 高
    int width;    // 宽
    int src[LEN]; // 原始数组
    int i;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &src[i]);
    }
    // 计算宽高
    for (i = 1; i <= n; i++) {
        if (i * i >= n && n % i == 0) {
            height = i;
            width = n / i;
            break;
        }
    }
    // 对原始数组进行递减排序
    qsort(src, n, sizeof(int), compare);

    int matrix[LEN]; // 矩阵
    int w = width;   // 可变宽
    int h = height;  // 可变高
    int x = -1;      // 初始x位置
    int y = 0;       // 初始y位置
    int len = 0;     // 矩阵长度

    while (w > 0 && h > 0) {
        /*
            在这里给大家分析下, 为什么每次需要保证h > 0, 或者
            w > 0. 如果没有这两个保证, 将只能得到21分, 有2个  
            测试点过不去.
            假如现在只剩下最后一行, 假设高为1, 宽为6, 这个时候
            我们走到终点, 整个矩阵遍历就结束了, 但此时的下一步
            往下走也就是高减去1为0, 而宽还是6. 因为高为0了, 所以
            向下不会走也就是不动, 但是再接着往左走, 这个时候因为  
            宽不为0, 还会接着遍历, 这就出问题了. 因此每次都必须
            要检测h > 0 或者 w > 0
        */

        // 向右
        for (i = 0; i < w && h > 0; i++) {
            x++;
            matrix[x + y * width] = src[len++];
        }
        h--; // 这里也可以 if (h == 0) break; 下同理
        // 向下
        for (i = 0; i < h && w > 0; i++) {
            y++;
            matrix[x + y * width] = src[len++];
        }
        w--;
        // 向左
        for (i = 0; i < w && h > 0; i++) {
            x--;
            matrix[x + y * width] = src[len++];
        }
        h--;
        // 向上
        for (i = 0; i < h && w > 0; i++) {
            y--;
            matrix[x + y * width] = src[len++];
        }
        w--;
    }
    // 打印
    char ch;
    for (i = 0; i < len; i++) {
        if ((i + 1) % width == 0) {
            ch = '\n';
        } else {
            ch = ' ';
        }
        printf("%d%c", matrix[i], ch);
    }

    return 0;
}

int compare (const void *a, const void *b) {
    int arg1 = *(int*)a;
    int arg2 = *(int*)b;
    return arg2 - arg1;
}
