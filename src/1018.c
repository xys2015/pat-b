#include <stdio.h>

void printWinGesture (int b, int c, int j);
void judge (char a, char b);

int ac = 0;  // ����Cʤ�Ĵ���
int aj = 0;  // ����Jʤ�Ĵ���
int ab = 0;  // ����Bʤ�Ĵ���
int bc = 0;  // ����Cʤ�Ĵ���
int bj = 0;  // ����Jʤ�Ĵ���
int bb = 0;  // ����Bʤ�Ĵ���
int ave = 0; // ƽ�ִ���

int main () {
    char a;
    char b;
    int awin = 0; // ��ʤ���ܴ���
    int alose = 0; // �׸����ܴ���
    int n;
    int i;

    scanf("%d", &n);
    getchar();
    for (i=1; i<=n; i++) {
        scanf("%c %c", &a, &b);
        getchar();
        judge(a, b);
    }
    awin = ac + aj + ab;
    alose = n - awin - ave;
    printf("%d %d %d\n", awin, ave, alose);
    printf("%d %d %d\n", alose, ave, awin);

    printWinGesture(ab, ac, aj);
    printf(" ");
    printWinGesture(bb, bc, bj);
    printf("\n");

    return 0;
}

// ��ӡ����������������ʾ����ĸ
void printWinGesture (int b, int c, int j) {
    int max = b;
    if (c > b && c >= j) {
        printf("C");
    } else if (j > b && j > c) {
        printf("J");
    } else {
        printf("B");
    }
}

// ��¼ƽ�ֵĴ���, �Լ����ҷֱ���CBJʤ�Ĵ���
void judge (char a, char b) {
    if (a == b) {
        ave++;
    } else if (a == 'C' && b == 'J') {
        ac++;
    } else if (a == 'J' && b =='B') {
        aj++;
    } else if (a == 'B' && b == 'C') {
        ab++;
    } else if (a == 'C' && b == 'B') {
        bb++;
    } else if (a == 'J' && b == 'C') {
        bc++;
    } else if (a == 'B' && b == 'J') {
        bj++;
    }
}
