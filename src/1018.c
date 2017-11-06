#include <stdio.h>

void printWinGesture (int b, int c, int j);
void judge (char a, char b);

int ac = 0;  // 甲用C胜的次数
int aj = 0;  // 甲用J胜的次数
int ab = 0;  // 甲用B胜的次数
int bc = 0;  // 乙用C胜的次数
int bj = 0;  // 乙用J胜的次数
int bb = 0;  // 乙用B胜的次数
int ave = 0; // 平局次数

int main () {
    char a;
    char b;
    int awin = 0; // 甲胜的总次数
    int alose = 0; // 甲负的总次数
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

// 打印三个数中最大的数表示的字母
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

// 记录平局的次数, 以及甲乙分别用CBJ胜的次数
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
