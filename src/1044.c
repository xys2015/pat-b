/*
火星人是以13进制计数的：
                     0
地球人的0被火星人称为 tret
地球人数字1到12的火星文分别为
1     2    3    4    5    6    7    8   9    10   11   12
jan, feb, mar, apr, may, jun, jly, aug, sep, oct, nov, dec
火星人将进位以后的12个高位数字分别称为
1     2    3    4    5    6    7    8    9    10  11   12
tam, hel, maa, huh, tou, kes, hei, elo, syy, lok, mer, jou
例如地球人的数字“29”翻译成火星文就是“hel mar”

而火星文“elo nov”对应地球数字“11  5”。为了方便交流，
请你编写程序实现地球和火星数字之间的互译。

输入格式：
                       [1, 99] 
输入第一行给出一个正整数N（<100），随后N行，每行给出一个[0, 169)区间内的数字 —— 或者是地球文，或者是火星文。

输出格式：

对应输入的每一行，在一行中输出翻译后的另一种语言的数字。

输入样例：
4
29
5
elo nov
tam
输出样例：
hel mar
may
115
13
*/
#include <stdio.h>
#include <string.h>

int main (void) {
    int n;
    char units[13][10] = {
        "tret", "jan", "feb", "mar", "apr", "may", "jun",
        "jly", "aug", "sep", "oct", "nov", "dec"
    };
    char tens[13][10] = {
        "tret", "tam", "hel", "maa", "huh", "tou", "kes",
        "hei", "elo", "syy", "lok", "mer", "jou"
    };
    char temp[10];
    int num;
    int m1;
    int m2;
    char tm1[10];
    char tm2[10];
    int sum = 0;
    int i;
    int j;

    scanf("%d", &n);
    getchar(); // 丢弃Enter
    for (j=1; j<=n; j++) {
        gets(temp);
        if (temp[0] >= '0' && temp[0] <= '9') {
        // 地球语转火星文
            sscanf(temp, "%d", &num);
            printf("%d\n", num);
            m1 = num / 13;
            m2 = num % 13;
            if (m1 != 0) {
                if (m2 == 0) {
                    printf("%s\n", tens[m1]);
                } else {
                    printf("%s ", tens[m1]);
                    printf("%s\n", units[m2]);
                }
            } else {
                printf("%s\n", units[m2]);
            }
        } else {
        // 火星文转地球语
        // 012 4567
        // elo nov
            int sum = 0;
            int len = strlen(temp);
            if (len <= 4) {
                sscanf(temp, "%s", tm1);
                for (i = 0; i < 13; i++) {
                    if (strcmp(tm1, tens[i]) == 0) {
                        sum += i * 13;
                    }
                    if (strcmp(tm1, units[i]) == 0) {
                        sum += i;
                    }
                }
                printf("%d\n", sum);
            } else {
                sscanf(temp, "%s %s", tm1, tm2);
                for (i = 0; i < 13; i++) {
                    if (strcmp(tm1, tens[i]) == 0) {
                        sum += i * 13;
                    }
                    if (strcmp(tm2, units[i]) == 0) {
                        sum += i;
                    }
                }
                printf("%d\n", sum);
            }
        }
    }

    return 0;
}
