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
#include <ctype.h>
int strToNum (char str[]);

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
        // printf("%s\n", temp);
        if (temp[0] >= '0' && temp[0] <= '9') {
        // 地球语转火星文
            num = strToNum(temp);
            // printf("%d\n", num);
            m1 = num / 13;
            m2 = num % 13;
            if (m1 != 0) {
                printf("%s ", tens[m1]);
            }
            printf("%s\n", units[m2]);
        } else {
        // 火星文转地球语
        // 012 4567
        // elo nov
            if (strlen(temp) == 8) {
            // 说明火星文个位是0
                tm1[0] = temp[0];    
                tm1[1] = temp[1];
                tm1[2] = temp[2];
                tm1[3] = '\0';
                for (i=0; i<13; i++) {
                    if (strcmp(tens[i], tm1) == 0) {
                        // printf("%s\n", tens[i]);
                        // printf("%s\n", tm1);
                        // printf("i: %d\n", i);
                        printf("%d\n", i * 13);
                    }
                }
                // tm2[0] = temp[4];
                // tm2[1] = temp[5];
                // tm2[2] = temp[6];
                // tm2[3] = temp[7];
                // tm2[4] = '\0';
            } else if (strlen(temp) == 7) {
                tm1[0] = temp[0];    
                tm1[1] = temp[1];
                tm1[2] = temp[2];
                tm1[3] = '\0';
                tm2[0] = temp[4];
                tm2[1] = temp[5];
                tm2[2] = temp[6];
                tm2[3] = '\0';
                // printf("\n\n");
                // printf("%s\n", tm1);
                // printf("%s\n", tm2);
                for (i=0; i<13; i++) {
                    if (strcmp(tens[i], tm1) == 0) {
                        sum += i * 13;
                        // printf("%s\n", tens[i]);
                        // printf("%s\n", tm1);
                        // printf("i: %d\n", i);
                    }
                    if (strcmp(units[i], tm2) == 0) {
                        sum += i;
                    }
                }
                printf("%d\n", sum);
            } else if (strlen(temp) == 3) {
                tm1[0] = temp[0];    
                tm1[1] = temp[1];
                tm1[2] = temp[2];
                tm1[3] = '\0';
                for (i=0; i<13; i++) {
                    if (strcmp(tens[i], tm1) == 0) {
                        printf("%d\n", i * 13);
                    }
                    if (strcmp(units[i], tm1) == 0) {
                        printf("%d\n", i);
                    }
                }
            } else {
                printf("0\n");
            }
        }
    }

    return 0;
}

int strToNum (char str[]) {
    int len = strlen(str);
    int num = 0;
    int i;
    for (i=0; i<len; i++) {
        num = num * 10 + str[i] - '0';
    }
    return num;
}
