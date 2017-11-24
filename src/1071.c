#include <stdio.h>

int main (void) {
    int total;  // 玩家现在手里的钱
    int k;      // 游戏次数
    int n1;
    int n2;
    int b;     // 0赌小, 1赌大
    int t;     // 玩家下注的筹码数
    int i;

    scanf("%d %d", &total, &k);
    for (i = 1; i <= k; i++) {
        scanf("%d %d %d %d", &n1, &b, &t, &n2);
        if (total == 0) {
            printf("Game Over.\n");
            break;
        }
        if (total - t < 0) {
            printf("Not enough tokens.  Total = %d.\n", total);
        } else {
            if (b == 0) {
                if (n2 < n1) {
                    total += t;
                    printf("Win %d!  Total = %d.\n", t, total);
                } else {
                    total -= t;
                    printf("Lose %d.  Total = %d.\n", t, total);
                }
            }
            if (b == 1) {
                if (n2 > n1) {
                    total += t;
                    printf("Win %d!  Total = %d.\n", t, total);
                } else {
                    total -= t;
                    printf("Lose %d.  Total = %d.\n", t, total);
                }
            }
        }
    }

    return 0;
}
