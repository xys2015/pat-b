#include <stdio.h>
#include <string.h>
int main()
{
    char A[101], B[101];
    char encrypt[] = "0123456789JQK";

    scanf("%s %s", A, B);
    int lenA = strlen(A);
    int lenB = strlen(B);
    int maxlen = lenA > lenB ? lenA : lenB;
    int a, b;

    for(int i = 0; i < maxlen; i++)
    {
        a = lenA + i - maxlen < 0 ? 0 : A[lenA + i - maxlen] - '0';
        b = lenB + i - maxlen < 0 ? 0 : B[lenB + i - maxlen] - '0';
        if((maxlen - i) % 2) {
            putchar(encrypt[(a + b) % 13]); // 奇数
        } else {
            int res;
            // putchar('0' + (b - a < 0 ? b - a + 10 : b - a));
            res = b - a < 0 ? b - a + 10 : b - a; // 偶数
            printf("%d", res);
        }
    }

    return 0;
}

/*
正确: 
56456487878 11212147788995542111
123456789
00000000056456487878
11212147788995542111
1121214770204Q1K5949

11212147731519969383
*/
