#include <stdio.h>

void printChar (int times, char ch);
void printInt (int times);

int main () {
    int n;
    int i;
    int m1; // ��λ
    int m2; // ʮλ
    int m3; // ��λ
    scanf("%d", &n);

    if (n < 10) {
        printInt(n);
        printf("\n");
    } else if (n >= 100) {
        m1 = (int)(n / 100);
        m2 = ((int)(n / 10)) % 10;
        m3 = n % 10;
        printChar(m1, 'B');
        printChar(m2, 'S');
        printInt(m3);
        printf("\n");
    } else {
        m2 = (int)(n / 10);
        m3 = n % 10;
        printChar(m2, 'S');
        printInt(m3);
    }

    return 0;
}

// ����: times��ӡ���ٴ�, ��Ҫ��ӡ���ַ�
void printChar (int times, char ch) {
    int i;
    for (i=1; i<=times; i++) {
        printf("%c", ch);
    }
}

void printInt (int times) {
    int i;
    for (i=1; i<=times; i++) {
        printf("%d", i);
    }
}
