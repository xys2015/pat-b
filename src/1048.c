/*
本题要求实现一种数字加密方法。
首先固定一个加密用正整数A，
对任一正整数B，
将其每1位数字与A的对应位置上的数字进行以下运算：

对奇数位，对应位的数字相加后对13取余——这里用J代表10、Q代表11、K代表12；
对偶数位，用B的数字减去A的数字，若结果为负数，则再加10。
这里令个位为第1位。

输入格式：

输入在一行中依次给出A和B，均为不超过100位的正整数，其间以空格分隔。

输出格式：

在一行中输出加密后的结果。
123456789
001234567     A
368782971     B
3695Q8118   Out
输入样例：
A       B
1234567 368782971
输出样例：
3695Q8118
*/
#include <stdio.h>
#include <string.h>
#define LEN 110
void encrypt (char cha, char chb, int mode);

int main (void) {
    char stra[LEN];
    char strb[LEN];
    char tmpa[LEN];
    char tmpb[LEN];
    int lena;
    int lenb;
    int mode;
    int i;
    int j;

    scanf("%s %s", tmpa, tmpb);
    lena = strlen(tmpa);
    lenb = strlen(tmpb);
    for (i = 0; i < LEN; i++) {
        stra[i] = '0';
        strb[i] = '0';
    }

    j = LEN - 1;
    for (i = lena - 1; i >= 0; i--) {
        stra[j--] = tmpa[i];
    }
    j = LEN - 1;
    for (i = lenb - 1; i >= 0; i--) {
        strb[j--] = tmpb[i];
    }

    mode = 1;
    for (i = 0; i < LEN; i++) {
        if (stra[i] != '0' || strb[i] != '0') {
            break;
        }
    }
    // encrypt(stra[i], strb[i], 1);
    for (; i < LEN; i++) {
        if (mode == 1) {
            encrypt(stra[i], strb[i], 1);
            mode = 0;
        } else {
            encrypt(stra[i], strb[i], 0);
            mode = 1;
        }
    }
/*
1234567 368782971
*/
    return 0;
}

// mode=0,偶数模式, mode=1,奇数模式
void encrypt (char cha, char chb, int mode) {
    int a = cha - '0';
    int b = chb - '0';
    int res;

    if (mode == 1) {
        res = (a + b) % 13;
        if (res == 10) {
            printf("J");
        } else if (res == 11) {
            printf("Q");
        } else if (res == 12) {
            printf("K");
        } else {
            printf("%d", res);
        }
    }
    if (mode == 0) {
        res = b - a < 0 ? b - a + 10 : b - a;
        printf("%d", res);
    }
}

