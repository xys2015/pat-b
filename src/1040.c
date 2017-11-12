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

struct pat {
    int num;
    int pos;
};
typedef struct pat s_pat;

s_pat find (s_pat s, char search, char end, char str[]);

int main (void) {
    s_pat p = {0 ,0};
    s_pat a = {0 ,0};
    s_pat t = {0 ,0};
    long long int mod = 1000000007;
    long long int total = 0;
    char str[100010];
    int len;
    int i;

    scanf("%s", str);
    len = strlen(str);
    // 把开头第一个'P'前面的东西拿掉
    for (i=0; i<len; i++) {
        if (str[i] == 'P') {
            p.pos = i;
            break;
        }
    }

    while (1) {
        p.num = 0;
        a.num = 0;
        t.num = 0;
        p = find(p, 'P', 'A', str);
        if (p.pos == len) break;
        a.pos = p.pos - 1;
        a = find(a, 'A', 'T', str);
        if (a.pos == len) break;
        t.pos = a.pos - 1;
        t = find(t, 'T', '\0', str);
        printf("%d %d %d\n", p.num, a.num, t.num);
        if (p.num == 0 || a.num == 0 || t.num == 0) break;
        total += p.num * a.num * t.num;
    }
    // printf("%lld\n", total % mod);
    return 0;
}

s_pat find (s_pat s, char search, char end, char str[]) {
    int i;
    int len = strlen(str);
    for (i=s.pos; i<len; i++) {
        if (str[i] == end && s.num != 0) {
            s.pos = i + 1;
            break;
        }
        if (str[i] == search) {
            s.num++;
        }
    }
    if (i == len) s.pos = len;
    return s;
}
// PAPAATTPATTT
// APPAPT