#include <stdio.h>

#define MAXSIZE 10001
int isPrime (int n);

/*
input:
5 27
output:
11 13 17 19 23 29 31 37 41 43
47 53 59 61 67 71 73 79 83 89
97 101 103
*/
int main () {
    int m;
    int n;
    int prime[MAXSIZE]; // 1-10000共保存1万个素数, 下标0不用
    int i = 2;
    int j = 1;
    int split = 10;    // 每10个字符打印一个换行
    char ch = ' ';     // 打印控制字符

    scanf("%d", &m);
    scanf("%d", &n);

    while (i) {
        if (isPrime(i) == 1) {
            prime[j] = i;
            j++;
        }
        if (j == MAXSIZE) {
            // 1万个素数, 准备完毕
            break;
        }
        i++;
    }

    j = 0; // 现在j用来, 打印控制
    for (i=m; i<=n; i++) {
        j++;
        if (j % split == 0) {
            ch = '\n';
        } else {
            ch = ' ';
        }
        // 最后一个数也是\n
        if (i == n) {
            ch = '\n';
        }
        printf("%d%c", prime[i], ch);
    }

    return 0;
}

// 是返回1, 不是返回0
int isPrime (int n) {
    int i = 2;
    int flag = 1;
    while (i * i <= n) {
        if (n % i ==0 ) {
            flag = 0;
            break;
        }
        i++;
    }
    return flag;
}
