/*
字符串APPAPT中包含了两个单词“PAT”，其中
第一个PAT是第2位(P),第4位(A),第6位(T)；
第二个PAT是第3位(P),第4位(A),第6位(T)。

现给定字符串，问一共可以形成多少个PAT？

输入格式：

输入只有一行，包含一个字符串，长度不超过10^5，只包含P、A、T三种字母。

输出格式：

在一行中输出给定字符串中包含多少个PAT。由于结果可能比较大，只输出对10 0000 0007取余数的结果。

输入样例：
APPAPT
输出样例：
2
*/
#include <stdio.h>
#include <string.h>

int main (void) {
    long long int nump = 0; 
    long long int numa = 0;
    long long int numt = 0;
    long long int numpat = 0;
    long long int mod = 1000000007;
    char str[100010];
    int len;
    int pi = 0;
    int flag = 1; // 循环结束标志
    int lastp = 0; // 最后一个P的位置
    int curp;
    int i;

    scanf("%s", str);
    len = strlen(str);
    for (i=0; i<len; i++) {
        if (str[i] == 'P') nump++;
        if (str[i] == 'A') numa++;
        if (str[i] == 'T') numt++;
    }
    if (nump != 0 && numa != 0 && numt != 0) {
        flag = 1;
    } else {
        flag = 0;
    }
    // printf("%lld %lld %lld\n", nump, numa, numt);
    if (flag == 1) {
        for (i=len-1; i>=0; i--) {
            if (str[i] == 'P') {
                lastp = i;
                break;
            }
        }        
    }
    while (flag == 1) {
        nump = 0;
        numa = 0;
        numt = 0;
        for (i=pi; i<len; i++) {
            if (str[i] == 'A') {
                pi = i + 1;
                break;
            }
            if (str[i] == 'P') {
                nump++;
                curp = i;
            }
        }
        for (; i<len; i++) {
            if (str[i] == 'T') {
                break;
            }
            if (str[i] == 'A') {
                numa++;
            }
        }
        for (; i<len; i++) {
            if (str[i] == 'T') {
                numt++;
            }
        }
        if (i == len && curp == lastp) {
            flag = 0;
        }
        numpat += nump * numa * numt;
    }
    printf("%lld\n", numpat % mod);

    return 0;
}
