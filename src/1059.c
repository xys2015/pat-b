#include <stdio.h>
#define LEN 10010
int isPrime (int n);
// -1 领过奖了 0不存在 其它就是位置序号
int main (void) {
    int pnum;
    int snum;
    int stu[LEN] = {0};
    int pno;
    int i;

    scanf("%d", &pnum);
    for (i = 1; i <= pnum; i++) {
        scanf("%d", &pno);
        stu[pno] = i;
    }
    scanf("%d", &snum);
    for (i = 1; i <= snum; i++) {
        scanf("%d", &pno);
        if (stu[pno] == 1) {
            printf("%04d: Mystery Award\n", pno);
            stu[pno] = -1;
        } else if (stu[pno] == 0) {
            printf("%04d: Are you kidding?\n", pno);
        } else if (stu[pno] == -1) {
            printf("%04d: Checked\n", pno);
        } else if (isPrime(stu[pno]) == 1) {
            printf("%04d: Minion\n", pno);
            stu[pno] = -1;
        } else {
            printf("%04d: Chocolate\n", pno);
            stu[pno] = -1;
        }
    }

    return 0;
}

// 0不是素数 1是素数
// 从2开始
int isPrime (int n) {
    int i = 2;
    while (i * i <= n) {
        if (n % i == 0) return 0;
        i++;
    }
    return 1;
}
