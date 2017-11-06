#include <stdio.h>

int part (char *str, char ch);
int mypow (int x);

int main () {
    char A[11];
    char DA;
    char B[11];
    char DB;
    long int PA = 0;
    long int PB = 0;

    scanf("%s %c %s %c", A, &DA, B, &DB);
    PA = part(A, DA);
    PB = part(B, DB);
    printf("%ld\n", PA + PB);

    return 0;
}

int part (char *str, char ch) {
    char *ptr = str;
    int num = (int)(ch - '0'); // Ҫ�ҵ�����
    int repeat = 0;            // ��ͬ���ֵĸ���
    int i;
    long int result = 0;

    while (*ptr != '\0') {
        if (*ptr == ch) {
            repeat++;
        }
        ptr++;
    }
    for (i=0; i<=(repeat-1); i++) {
        result += (long int)(num * mypow(i));
    }

    return result;
}

// ���� 10^x
int mypow (int x) {
    int res = 1;
    int i;
    for (i=1; i<=x; i++) {
        res = res * 10;
    }
    return res;
}
