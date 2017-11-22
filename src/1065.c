#include <stdio.h>
#include <stdlib.h>
#define LEN 100010
int main (void) {
    int n;              // 情侣对数
    int nid[LEN];       // 互相存情侣号
    int m;              // 参加派对的总人数
    int mid[LEN] = {0}; // 1有这个人 2落单
    int single = 0;     // 落单客人的总人数
    int i;
    int tmp1;
    int tmp2;

    for (i = 0; i < LEN; i++) {
        nid[i] = -1; // 代表此人不存在
    }
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d %d", &tmp1, &tmp2);
        // 互相存放自己的情侣号
        nid[tmp1] = tmp2;
        nid[tmp2] = tmp1;
    }
    scanf("%d", &m);
    for (i = 0; i < m; i++) {
        scanf("%d", &tmp1);
        mid[tmp1] = 1; // 标记为1, 这位客人参加了派对
    }

    for (i = 0; i < LEN; i++) {
        // i参加派对客人id
        if (mid[i] == 1) {
            if (nid[i] == -1) {
                single++;
                mid[i] = 2;
            } else {
                if (mid[nid[i]] != 1) {
                    single++;
                    mid[i] = 2;
                }
            }
        }
    }

    printf("%d\n", single);
    int first = 1;
    for (i = 0; i < LEN; i++) {
        if (mid[i] == 2) {
            if (first == 1) {
                // MD, 忘记了个5前面补零, 又耽误我
                // 1小时+ (这是测试点3)
                printf("%05d", i);
                first = 0;
            } else {
                printf(" %05d", i);
            }
        }
    }
    return 0;
}
