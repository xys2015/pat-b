#include <stdio.h>
#define LEN 40
int main (void) {
    int n;
    char nstr[5];       // 每个数
    int fno[LEN] = {0}; // 朋友证号
    int dfno = 0;       // 不同的朋友证
    int fsum;           // 各位数字的和
    int first = 1;      // 控制打印
    char *p;
    int i;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%s", nstr);
        p = nstr;
        fsum = 0;
        while (*p != '\0') {
            fsum += *p - '0';
            p++;
        }
        if (fno[fsum] == 0) {
            // 标记为1, 代表这个朋友号有
            fno[fsum] = 1;
            dfno++;
        }
    }
    printf("%d\n", dfno);
    for (i = 0; i < LEN; i++) {
        if (fno[i] == 1) {
            if (first == 1) {
                printf("%d", i);
                first = 0;
            } else {
                // 用这种方式来搞空格输出, 不要太方便
                // 无需知道到底有多少个数满足条件
                printf(" %d", i);
            }
        }
    }
    
    return 0;
}
