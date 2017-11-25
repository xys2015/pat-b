#include <stdio.h>
#include <string.h>
#define LEN 30

int main (void) {
    char table[LEN];
    int len;
    char num1[LEN];
    char num2[LEN];
    char res[LEN];
    char tmp1[LEN];
    char tmp2[LEN];
    int i;
    int j;

    table[0] = '0';
    scanf("%s", table + 1);
    scanf("%s", tmp1);
    scanf("%s", tmp2);
    len = strlen(table);
    for (i = 0; i < len; i++) {
        num1[i] = '0';
        num2[i] = '0';
        res[i] = '0';
    }
    i = len - 1;
    for (j = strlen(tmp1) - 1; j >= 0; j--) num1[i--] = tmp1[j];
    num1[len] = '\0'; // 这个不能少
    i = len - 1;
    for (j = strlen(tmp2) - 1; j >= 0; j--) num2[i--] = tmp2[j];
    num2[len] = '\0';

    int now;
    int carry = 0; // 进位
    int sys;       // 进制
    for (i = len - 1; i >= 0; i--) {
        if (table[i] == '0') {
            sys = 10;
        } else {
            sys = table[i] - '0';
        }
        now = (num1[i] - '0') + (num2[i] - '0') + carry;
        if (now < sys) {
            res[i] = now + '0';
            carry = 0;
        } else {
            carry = 1;
            res[i] = now - sys + '0';
        }
    }
    res[len] = '\0';

    for (i = 0; i < len; i++) {
        if (res[i] != '0') break;
    }
    if (i == len) {
        printf("0");
    } else {
        for (; i < len; i++) {
            printf("%c", res[i]);
        }
    }

    return 0;
}
