#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int gcd (int m, int n);
void printNum (char a1, int a2, int a3);

int main (void) {
    // 符号 分子 分母, 符号 分子 分母
    char a1;
    int a2 = 0;
    int a3 = 0;
    char b1;
    int b2 = 0;
    int b3 = 0;
    int gcd1; // 最大公约数
    int gcd2; // 最大公约数
    int lcm; // 分母最小公倍数
    char str1[50]; // 第1个数
    char str2[50]; // 第2个数
    int len1;
    int len2;
    char tsym; // 临时符号
    int i;

    scanf("%s", str1);
    scanf("%s", str2);
    len1 = strlen(str1);
    len2 = strlen(str2);
    // 对a1, a2, a3赋值
    if (str1[0] == '-') {
        a1 = str1[0];
        i = 1;
    } else {
        a1 = '+';
        i = 0;
    }
    for (; i<len1; i++) {
        if (str1[i] == '/') {
            i++;
            break;
        }
        a2 = (a2 * 10) + (str1[i] - '0');
    }
    for (; i<len1; i++) {
        a3 = (a3 * 10) + (str1[i] - '0');
    }
    // 对b1, b2, b3赋值
    if (str2[0] == '-') {
        b1 = str2[0];
        i = 1;
    } else {
        b1 = '+';
        i = 0;
    }
    for (; i<len2; i++) {
        if (str2[i] == '/') {
            i++;
            break;
        }
        b2 = (b2 * 10) + (str2[i] - '0');
    }
    for (; i<len2; i++) {
        b3 = (b3 * 10) + (str2[i] - '0');
    }

    // 分子为零
    if (a2 == 0 && b2 ==0 ) {
        printf("0 + 0 = 0\n");
        printf("0 - 0 = 0\n");
        printf("0 * 0 = 0\n");
        printf("0 / 0 = Inf\n");
    } else if (a2 == 0 && b2 != 0) {
        // +
        printf("0 + ");
        printNum(b1, b2, b3);
        printf(" = ");
        printNum(b1, b2, b3);
        printf("\n");
        // - 
        printf("0 - ");
        printNum(b1, b2, b3);
        printf(" = ");
        if (b1 == '+') tsym = '-';
        else if (b1 == '-') tsym = '+';
        printNum(tsym, b2, b3);
        printf("\n");
        // *
        printf("0 * ");
        printNum(b1, b2, b3);
        printf(" = 0");
        printf("\n");
        // 除法
        printf("0 / ");
        printNum(b1, b2, b3);
        printf(" = 0");
        printf("\n");
    } else if (a2 != 0 && b2 == 0) {
        // +
        printNum(a1, a2, a3);
        printf(" + 0 = ");
        printNum(a1, a2, a3);
        printf("\n");
        // -
        printNum(a1, a2, a3);
        printf(" - 0 = ");
        printNum(a1, a2, a3);
        printf("\n");
        // *
        printNum(a1, a2, a3);
        printf(" * 0 = 0");
        printf("\n");
        // 除法
        printNum(a1, a2, a3);
        printf(" / 0 = Inf");
        printf("\n");
    } else {
        // 化简
        gcd1 = gcd(a2, a3);
        gcd2 = gcd(b2, b3);
        a2 = a2 / gcd1;
        a3 = a3 / gcd1;
        b2 = b2 / gcd2;
        b3 = b3 / gcd2;

        int c2 = a2 * b3; // 通分后分子
        int c3 = a3 * b3; // 通分后分母
        int d2 = b2 * a3;
        int d3 = c3;
        char res1; // 计算结果分子
        int res2;  // 计算结果分母
        int res3 = d3;
        char symbol; // 当前算术符号
        char old;    // 原来的符号
        int oldb2;
        int oldb3;
        // 自带符号有4种情况, ++ +- -+ --
        // 中间符号有2种情况, + -

        /* 加法和减法模块开始 */
        // 加法
        symbol = '+';
        if (a1 == '+' && b1 == '+') {
            res1 = '+';
            res2 = c2 + d2;
            printNum(a1, a2, a3);
            printf(" %c ", symbol);
            printNum(b1, b2, b3);
            printf(" = ");
            printNum(res1, res2, res3);
            printf("\n");
        } else if (a1 == '-' && b1 == '-') {
            res1 = '-';
            res2 = c2 + d2;
            printNum(a1, a2, a3);
            printf(" %c ", symbol);
            printNum(b1, b2, b3);
            printf(" = ");
            printNum(res1, res2, res3);
            printf("\n");
        } else {
            if (c2 >= d2) res1 = a1;
            else res1 = b1;
            res2 = abs(c2 - d2);
            printNum(a1, a2, a3);
            printf(" %c ", symbol);
            printNum(b1, b2, b3);
            printf(" = ");
            printNum(res1, res2, res3);
            printf("\n");
        }

        // 减法
        symbol = '-';
        old = b1;
        if (b1 == '+') b1 = '-';
        if (b1 == '-') b1 = '+';
        if (a1 == '+' && b1 == '+') {
            res1 = '+';
            res2 = c2 + d2;
            printNum(a1, a2, a3);
            printf(" %c ", symbol);
            printNum(old, b2, b3);
            printf(" = ");
            printNum(res1, res2, res3);
            printf("\n");
        } else if (a1 == '-' && b1 == '-') {
            res1 = '-';
            res2 = c2 + d2;
            printNum(a1, a2, a3);
            printf(" %c ", symbol);
            printNum(old, b2, b3);
            printf(" = ");
            printNum(res1, res2, res3);
            printf("\n");
        } else {
            if (c2 >= d2) res1 = a1;
            else res1 = b1;
            res2 = abs(c2 - d2);
            printNum(a1, a2, a3);
            printf(" %c ", symbol);
            printNum(old, b2, b3);
            printf(" = ");
            printNum(res1, res2, res3);
            printf("\n");
        }
        // 把b1的符号还原回来
        b1 = old;
        /* 加法和减法模块结束 */

        /* 乘法和除法模块开始 */
        // 乘法
        symbol = '*';
        if (a1 == '+' && b1 == '+') {
            res1 = '+';
            res2 = a2 * b2;
            res3 = a3 * b3;
            printNum(a1, a2, a3);
            printf(" %c ", symbol);
            printNum(b1, b2, b3);
            printf(" = ");
            printNum(res1, res2, res3);
            printf("\n");
        } else if (a1 == '-' && b1 == '-') {
            res1 = '+';
            res2 = a2 * b2;
            res3 = a3 * b3;
            printNum(a1, a2, a3);
            printf(" %c ", symbol);
            printNum(b1, b2, b3);
            printf(" = ");
            printNum(res1, res2, res3);
            printf("\n");
        } else {
            res1 = '-';
            res2 = a2 * b2;
            res3 = a3 * b3;
            printNum(a1, a2, a3);
            printf(" %c ", symbol);
            printNum(b1, b2, b3);
            printf(" = ");
            printNum(res1, res2, res3);
            printf("\n");
        }

        // 除法
        symbol = '/';
        oldb2 = b2;
        oldb3 = b3;
        // 取倒数, 也就是交换b2和b3
        i = b2;
        b2 = b3;
        b3 = i;
        if (a1 == '+' && b1 == '+') {
            res1 = '+';
            res2 = a2 * b2;
            res3 = a3 * b3;
            printNum(a1, a2, a3);
            printf(" %c ", symbol);
            printNum(b1, oldb2, oldb3);
            printf(" = ");
            printNum(res1, res2, res3);
            printf("\n");
        } else if (a1 == '-' && b1 == '-') {
            res1 = '+';
            res2 = a2 * b2;
            res3 = a3 * b3;
            printNum(a1, a2, a3);
            printf(" %c ", symbol);
            printNum(old, oldb2, oldb3);
            printf(" = ");
            printNum(res1, res2, res3);
            printf("\n");
        } else {
            res1 = '-';
            res2 = a2 * b2;
            res3 = a3 * b3;
            printNum(a1, a2, a3);
            printf(" %c ", symbol);
            printNum(old, oldb2, oldb3);
            printf(" = ");
            printNum(res1, res2, res3);
            printf("\n");
        }
        /* 乘法和除法模块结束 */
    }

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

// 格式化打印分数
// 参数: a1符号, a2分子, a3分母
void printNum (char a1, int a2, int a3) {
    int tgcd = gcd(a2, a3);
    a2 = a2 / tgcd;
    a3 = a3 / tgcd;
    if (a2 == a3) {
        if (a1 == '+') {
            printf("1");
        }
        if (a1 == '-') {
            printf("(-1)");
        }
    } else if (a2 > a3 && a3 != 1) {
        if (a1 == '+') {
            printf("%d %d/%d", (int)(a2/a3), a2%a3, a3);
        }
        if (a1 == '-') {
            printf("(-%d %d/%d)", (int)(a2/a3), a2%a3, a3);
        }
    } else if (a2 > a3 && a3 == 1) {
        if (a1 == '+') {
            printf("%d", a2);
        }
        if (a1 == '-') {
            printf("(-%d)", a2);
        }
    } else {
        if (a1 == '+') {
            printf("%d/%d", a2, a3);
        }
        if (a1 == '-') {
            printf("(-%d/%d)", a2, a3);
        }
    }
}
