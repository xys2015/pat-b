#include <stdio.h>

int main () {
    char str[50];
    int len = 0;
    int itimes;
    char temp;
    int i;
    int j;

    for (i=0; i<=9; i++) {
        scanf("%d", &itimes);
        for (j=1; j<=itimes; j++) {
            str[len] = i + '0';
            len++;
        }
    }
    // 如果第一个位置是0, 则需要交换
    if (str[0] == '0') {
        for (i=0; i<len; i++) {
            if (str[i] != '0') {
                // 交换0 和 i, 注意只有第一次需要交换
                temp = str[i];
                str[i] = '0';
                str[0] = temp;
                break;
            }
        }
    }
    // 循环输出
    for (i=0; i<len; i++) {
        putchar(str[i]);
    }
    printf("\n");

    return 0;
}
