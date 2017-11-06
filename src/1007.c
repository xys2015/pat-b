#include <stdio.h>

int isPrime (int n);

int main () {
    int pre = 3; // 保存前一个素数的值
    int result = 0; // 素数对个数
    int i;
    int n;

    scanf("%d", &n); // 输入的n若果小于5, 直接返回0, 这是我们人工判断
    for (i=5; i<=n; i++) {
        if (isPrime(i) == 1) {
            if ((i - pre) == 2) {
                result += 1;
            }
            pre = i; // 只要当前的i为素数, 我们就更新pre的值
        }
    }
    printf("%d\n", result);

    return 0;
}

// 是返回1, 不是返回0
int isPrime (int n) {
    int i = 2;
    int flag = 1; // 默认n是素数
    while (i * i <= n) {
        if (n % i == 0) {
            flag = 0;
            break;
        }
        i++;
    }
    return flag;
}
