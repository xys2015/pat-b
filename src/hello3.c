#include <stdio.h>

// 输入: 十进制整数n (n >= 0)
// 输出: 二进制字符串
// 43(10) --> 101011(2)
// 9(10) --> 1001(2)

int getLength (int n);

int main () {
    int int10 = 2;
    char bin2[100];
    int len;

    len = getLength(int10);
    bin2[len] = '\0';
    len = len - 1; // 数组从下标0开始
    while (int10 != 0) {
        bin2[len] = (char)(int10 % 2 + '0');  // 整数转字符
        int10 = (int10 - (int10 % 2)) / 2;
        len = len - 1;
    }
    printf("%s\n", bin2);

    return 0;
}

int getLength (int n) {
    int i = 0;
    while (n != 0) {
        i++;
        n = (n - (n % 2)) / 2;
    }
    return i;
}