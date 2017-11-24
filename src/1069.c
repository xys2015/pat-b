#include <stdio.h>
#include <string.h>

#define LEN1 1010
#define LEN2 30
int isPrise (char pname[][LEN2], int plen, char search[]);

int main (void) {
    int m;   // 转发的总量
    int n;   // 中奖间隔
    int s;   // 第一位中奖者的序号(从1开始)
    int i;
    char name[LEN1][LEN2];   // 网友的昵称(从1开始) 
    char pname[LEN1][LEN2];  // 维护一份中奖名单
    int plen = 0;            // 中奖名单长度

    scanf("%d %d %d", &m, &n, &s);
    for (i = 1; i <= m; i++) {
        scanf("%s", name[i]);
    }
    if (s > m) {
        printf("Keep going...\n");
    } else {
        i = s;
        while (i <= m) {
            while (isPrise(pname, plen, name[i]) != 0) {
                i++;
            }
            if (i <= m) {
                printf("%s\n", name[i]);
                strcpy(pname[plen++], name[i]);
                i += n;
            }
        }
    }

    return 0;
}

// 已经中过奖返回1, 没中过返回0
int isPrise (char pname[][LEN2], int plen, char search[]) {
    int i;
    for (i = 0; i < plen; i++) {
        if (strcmp(pname[i], search) == 0) {
            return 1;
        }
    }
    return 0;
}
