#include <stdio.h>

int main () {
    int a;
    int b;
    int n;
    int d;
    int len = 40;
    char res[len];
    int start = len;
    int i;

    scanf("%d %d %d", &a, &b, &d);
    n = a + b;
    if (n == 0) {
        printf("0\n"); // 对应测试点3
    } else {
        while (n != 0) {
            start--;
            res[start] = (n % d) + '0';
            n = n / d;
        }

        for (i=start; i<len; i++) {
            putchar(res[i]);
        }
        printf("\n");
    }

    return 0;
}
