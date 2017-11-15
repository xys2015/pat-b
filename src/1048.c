#include <stdio.h>
#include <string.h>
#define LEN 110
void encrypt (char cha, char chb, int mode);

int main (void) {
    char stra[LEN];
    char strb[LEN];
    int lena;
    int lenb;
    int lenmax;
    char a;
    char b;
    int posa;
    int posb;
    int i;
    int mode;

    // 从下标1开始赋值
    scanf("%s %s", stra + 1, strb + 1);
    stra[0] = '#'; // 下标0无用, 但是随便赋个值
    strb[0] = '#'; // 不然会出现各种垃圾吧毛病
    lena = strlen(stra) - 1; // lena就是数组下标最后一个
    lenb = strlen(strb) - 1;

    lenmax = lena > lenb ? lena : lenb;
    for (i = 1; i <= lenmax; i++) {
        posa = i + lena - lenmax; // 成功把2套逻辑, 抽象为
        posb = i + lenb - lenmax; // 一体
        a = posa > 0 ? stra[posa] : '0';
        b = posb > 0 ? strb[posb] : '0';
        if ((lenmax - i) % 2 == 0) {
            mode = 1; // 说明i是奇数
        } else {
            mode = 0; // 说明i是偶数
        }
        encrypt(a, b, mode);
    }
    
    return 0;
}

// mode=0, 偶数模式
// mode=1, 奇数模式
void encrypt (char cha, char chb, int mode) {
    char str[] = "0123456789JQK";
    int a = cha - '0';
    int b = chb - '0';
    int res;

    if (mode == 1) {
        res = (a + b) % 13;
        printf("%c", str[res]);
    }
    if (mode == 0) {
        res = b - a < 0 ? b - a + 10 : b - a;
        printf("%d", res);
    }
}
