/*
本题的基本要求非常简单：给定N个实数，计算它们的平均值。但复杂的是有些输入数据可能是非法的。一个“合法”的输入是[-1000，1000]区间内的实数，并且最多精确到小数点后2位。当你计算平均值的时候，不能把那些非法的数据算在内。

输入格式：

输入第一行给出正整数N（<=100）。随后一行给出N个实数，数字间以一个空格分隔。

输出格式：

对每个非法输入，在一行中输出“ERROR: X is not a legal number”，其中X是输入。最后在一行中输出结果：“The average of K numbers is Y”，其中K是合法输入的个数，Y是它们的平均值，精确到小数点后2位。如果平均值无法计算，则用“Undefined”替换Y。如果K为1，则输出“The average of 1 number is Y”。

输入样例1：
7
5 -3.2 aaa 9999 2.3.4 7.123 2.35
输出样例1：
ERROR: aaa is not a legal number
ERROR: 9999 is not a legal number
ERROR: 2.3.4 is not a legal number
ERROR: 7.123 is not a legal number
The average of 3 numbers is 1.38
输入样例2：
2
aaa -9999
输出样例2：
ERROR: aaa is not a legal number
ERROR: -9999 is not a legal number
The average of 0 numbers is Undefined
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int isLegalNum (char str[]);

int main (void) {
    int n;
    int i;
    char str[10000];
    double now;
    double sum = 0.0;
    int numOfLegal = 0;
    // [-1000，1000]
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%s", str);
        if (isLegalNum(str)) {
            sscanf(str, "%lf", &now);
            if (now >= -1000.0 && now <= 1000.0) {
                numOfLegal++;
                sum += now;
            } else {
                printf("ERROR: %s is not a legal number\n", str);    
            }
        } else {
            printf("ERROR: %s is not a legal number\n", str);
        }
    }
    if (numOfLegal == 0) {
        printf("The average of 0 numbers is Undefined");
    } else {
        printf("The average of %d numbers is %.2f", numOfLegal, sum / numOfLegal);
    }

    return 0;
}

// 先判断是不是合法的小数
// 1合法 0不合法
int isLegalNum (char str[]) {
    int len = strlen(str);
    // int res;
    int i;

    if (str[0] == '.')  return 0;
    if (str[0] == '-' && str[1] == '.')  return 0;
    if (str[0] == '-') {
        // res = 1;
    } else if (str[0] >= '0' && str[0] <= '9') {
        // res = 1;
    } else {
        return 0;
    }
    for (i = 1; i < len; i++) {
        if (str[i] == '.') {
            if (len - 1 == i + 2) {
                if (
                    (str[i + 1] >= '0' && str[i + 1] <= '9') &&
                    (str[i + 2] >= '0' && str[i + 2] <= '9')
                ) {
                    return 1;
                } else {
                    return 0;
                }
            } else if (len - 1 == i + 1) {
                if (str[i + 1] >= '0' && str[i + 1] <= '9') {
                    return 1;
                } else {
                    return 0;
                }
            } else {
                return 0;
            }
        }
        if (str[i] < '0' || str[i] > '9') {
            return 0;
        }
    }
    return 1;
}
