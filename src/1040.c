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
    int num; // 一共找到多少字符
    int pos; // 从什么位置开始找
    char cur; // 当前字符
    char next; // 下一个字符
};
typedef struct pat s_pat;

s_pat find (s_pat s, char str[], int len);

int main (void) {
    s_pat p = {0, 0, 'P', 'A'};
    s_pat a = {0, 0, 'A', 'T'};
    s_pat t = {0, 0, 'T', '\0'};
    long long int mod = 1000000007;
    long long int total = 0;
    char str[100010];
    int len;
    int flag;
    int i;

    scanf("%s", str);
    len = strlen(str);
    
    for (i=0; i<len; i++) {
        if (str[i] == 'P') p.num++;
        if (str[i] == 'A') a.num++;
        if (str[i] == 'T') t.num++;
    }
    if (p.num != 0 && a.num != 0 && t.num != 0) {
        flag = 1;
    } else {
        flag = 0;
    }

    while (flag == 1) {
        p.num = 0;
        a.num = 0;
        t.num = 0;
        p = find(p, str, len);
        if (p.pos == len) break;
        a.pos = p.pos;
        a = find(a, str, len);
        if (a.pos == len) break;
        t.pos = a.pos;
        t = find(t, str, len);
        // printf("%d %d %d\n", p.num, a.num, t.num);
        if (p.num == 0 || a.num == 0 || t.num == 0) break;
        total += p.num * a.num * t.num;
    }
    printf("%lld\n", total % mod);
    return 0;
}

s_pat find (s_pat s, char str[], int len) {
    int i;
    for (i=s.pos; i<len; i++) {
        if (str[i] == s.next && s.num != 0) {
            s.pos = i;
            break;
        }
        if (str[i] == s.cur) {
            s.num++;
        }
    }
    if (i == len) {
        s.pos = len;
    }
    return s;
}
// PAPAATTPATTT
// APPAPT