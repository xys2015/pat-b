#include <stdio.h>;

int main() {
    int n;
    int step = 0;
    scanf("%d", &n);
    while (n != 1) {
        if (n % 2 == 0) {
            n = n / 2;
            step++;
        } else {
            n = ((3 * n) + 1) / 2;
            step++;
        }
    }
    printf("%d", step);
    return 0;
}

// ԭ��: https://www.patest.cn/contests/pat-b-practise/1001