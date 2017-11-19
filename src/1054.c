#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void) {
    int n;
    char src[100];  // 原始字符串
    char dest[100]; // 保留2位小数的字符串 
    double sum = 0.0;
    int count = 0;
    double temp;
    int flag;       // 标记是否合法, 0合法, 1不合法
    int i;
    int j;

    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%s", src);
        sscanf(src, "%lf", &temp);
        sprintf(dest, "%.2f", temp);
        flag = 0;
        for (j = 0; j < strlen(src); j++) {
            if (src[j] != dest[j]) {
                flag = 1; // 不合法的数字
                break;
            }
        }
        if (flag == 1 || temp < -1000 || temp > 1000) {
            printf("ERROR: %s is not a legal number\n", src);
        } else {
            count++;
            sum += temp;
        }
    }
    if (count == 0) {
        printf("The average of 0 numbers is Undefined");
    } else if (count == 1) {
        // MMP简直要崩溃, 这里number没有"s" (测试点2)
        printf("The average of 1 number is %f", sum);
    } else {
        printf("The average of %d numbers is %.2f", count, sum / count);
    }

    return 0;
}
