#include <stdio.h>

int main () {
    char str[50];
    int len = 0;
    int itimes;
    char temp;
    int i;
    int j;

    for (i=0; i<=9; i++) {
        scanf("%d", &itimes);
        for (j=1; j<=itimes; j++) {
            str[len] = i + '0';
            len++;
        }
    }
    // �����һ��λ����0, ����Ҫ����
    if (str[0] == '0') {
        for (i=0; i<len; i++) {
            if (str[i] != '0') {
                // ����0 �� i, ע��ֻ�е�һ����Ҫ����
                temp = str[i];
                str[i] = '0';
                str[0] = temp;
                break;
            }
        }
    }
    // ѭ�����
    for (i=0; i<len; i++) {
        putchar(str[i]);
    }
    printf("\n");

    return 0;
}
