#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int gcd (int m, int n);

int main (void) {

    return 0;
}

// 求最大公约数
int gcd (int m, int n) {
    int mod = n; // 初始化成非0值
    while (mod != 0) {
        mod = m % n;
        m = n;
        n = mod;
    }
    return m;
}

