#include <stdio.h>

int  isSimple (int a, int b);

int main (void) {
    double n1;
    double m1;
    double r1;
    double n2;
    double m2;
    double r2;
    double temp;
    int first = 0;
    int k;
    int i;

    scanf("%lf/%lf %lf/%lf %d", &n1, &m1, &n2, &m2, &k);
    r1 = n1 / m1;
    r2 = n2 / m2;
    // 默认r1 < r2, 如果不是则交换
    if (r1 > r2) {
        temp = r1;
        r1 = r2;
        r2 = temp;
    }
    for (i = 1; i / (double)(k) < r2; i++) {
        if ( (i / (double)(k) > r1) && 
             (i / (double)(k) < r2) ) {
            if (isSimple(i, k) == 1) {
                if (first == 0) {
                    printf("%d/%d", i, k);
                    first = 1;
                } else {
                    // 这里有空格
                    printf(" %d/%d", i, k);
                }
            }
        }
    }

    return 0;
}

// 1最简形式 0非最简形式
int isSimple (int a, int b) {
    int i;
    for (i = 2; i <= a; i++) {
        if (a % i == 0 && b % i == 0) {
            return 0;
        }
    }
    return 1;
}
