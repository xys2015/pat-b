#include <stdio.h>

void swap (char *a, char *b);
void intToStr (int n, char str[]);
void sortStr (char str[], int type); // 1 big to small
int strToInt (char str[]);

int main () {
    int n;
    int big;
    int small;
    int blackHole = 6174;
    char str[10];

    scanf("%d", &n);
    if (n == blackHole) {
        printf("7641 - 1467 = 6174\n"); // 给我6174? OK, 直接写死!
    } else {
        while (n != blackHole) {
            intToStr(n, str);
            sortStr(str, 1);
            big = strToInt(str);   // 拿到大数
            sortStr(str, 0);
            small = strToInt(str); // 拿到小数
            if (big == small) {
                printf("%04d - %04d = %04d\n", big, small, 0);
                break;
            }
            n = big - small;
            printf("%04d - %04d = %04d\n", big, small, n);
        }
    }

    return 0;
}

// 正整数整数转字符串
// 参数: n, 待转换的整数, str[], 保存字符串的数组
void intToStr (int n, char str[]) {
    char cur;
    int i = 0;
    while (n != 0) {
        cur = (char)(n % 10) + '0';
        str[i] = cur;
        i++;
        n = n / 10;
    }
    str[i] = '\0';
    // 如果转换后的字符串不足4位, 人工补0
    if (i == 1) {
        str[1] = '0';
        str[2] = '0';
        str[3] = '0';
        str[4] = '\0';
    } else if (i == 2) {
        str[2] = '0';
        str[3] = '0';
        str[4] = '\0';
    } else if (i == 3) {
        str[3] = '0';
        str[4] = '\0';
    }
}

// 字符串转整数
int strToInt (char str[]) {
    char *ptr = str;
    int res = 0; // 转换后的整数
    while (*ptr != '\0') {
        res = res * 10 + (*ptr - '0');
        ptr++;
    }
    return res;
}

// 字符串排序, str长度必然是4
// type等于1, 从大到小排序, 等于0, 从小到大排序
void sortStr (char str[], int type) {
    int i;
    int j;
    for (i=1; i<=3; i++) {
        for (j=0; j<=3-i; j++) {
            if (type == 1 && str[j+1] > str[j]) {
                swap(&str[j], &str[j+1]);
            } else if (type == 0 && str[j+1] < str[j]) {
                swap(&str[j], &str[j+1]);
            }
        }
    }
}

// 交换两个字符变量
void swap (char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}
