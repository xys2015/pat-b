#include <stdio.h>

int main (void) {
    int m;
    int n;
    int a;
    int b;
    int c;
    char ch;
    int tmp;
    int i;
    int j;

    scanf("%d %d %d %d %d", &m, &n, &a, &b, &c);
    // 题目说了这么多就是一句话, 如果tmp在[a, b]打印c否则打印tmp
    for (i = 1; i <= m; i++) {
        ch = ' ';
        for (j = 1; j <= n; j++) {
            if (j == n) ch = '\n';
            scanf("%d", &tmp);
            if (tmp >= a && tmp <= b) {
                printf("%03d%c", c, ch);
            } else {
                printf("%03d%c", tmp, ch);
            }
        }
    }
    
    return 0;
}
