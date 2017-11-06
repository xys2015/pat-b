#include <stdio.h>

int main (void) {
    int weight[17] = {
        7, 9, 10, 5, 8, 4, 2, 1, 6, 3,
        7, 9, 10, 5, 8, 4, 2
    }; // 17个
    int m[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
    int wrong1 = 0; // 第1种错误
    int flag = 0;   // 只要发生错误就标记为1
    char id[19];    // 最后一位放 '\0'
    int n;
    int sum;
    int i;
    int j;

    scanf("%d", &n);
    for (i=1; i<=n; i++) {
        scanf("%s", id);
        id[18] = '\0';
        wrong1 = 0;
        // 第1种错误, 前17位有非数字
        for (j=0; j<=16; j++) {
            if (id[j] > '9' || id[j] < '0') {
                wrong1 = 1;
                flag = 1;
                // printf("opt1: %s\n", id);
                printf("%s\n", id);
                break;
            }
        }

        sum = 0;
        if (wrong1 == 0) {
            for (j=0; j<=16; j++) {
                sum += (id[j] - '0') * weight[j];
            }
            // printf("%d\n", sum);
            // 第2种错误, 校验值不正确
            if (m[sum % 11] != id[17]) {
                flag = 1;
                // printf("opt2: %s\n", id);
                printf("%s\n", id);
            }
        }
    }
    if (flag == 0) {
        printf("All passed\n");
    }
    return 0;
}
