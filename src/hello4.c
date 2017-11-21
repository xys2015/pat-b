#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int n, cnt = 0;
    char a[50], b[50];
    double temp, sum = 0.0;
    scanf("%d", &n);
/*
7
.5 -3.2 aaa 9999 2.3.4 7.123 2.35

7
5.656874587 -3.2 aaa 9999 2.3.4 7.123 2.35
*/
    for(int i = 0; i < n; i++) {
        scanf("%s", a);
        sscanf(a, "%lf", &temp); // 把a转成小数, 放在temp里
        sprintf(b, "%.2lf",temp); // 把temp转成小数放在b里
        printf("a: %s\n", a);
        printf("b: %s\n", b);
        printf("\n");
        // printf("a: %s\n", a);
        // printf("b: %s\n", b);
        int flag = 0;
        for(int j = 0; j < strlen(a); j++) {
            if(a[j] != b[j]) flag = 1;
        }
        if(flag || temp < -1000 || temp > 1000) {
            printf("ERROR: %s is not a legal number\n", a);
            continue;
        } else {
            sum += temp;
            cnt++;
        }
    }
    if(cnt == 1) {
        printf("The average of 1 number is %.2lf", sum);
    } else if(cnt > 1) {
        printf("The average of %d numbers is %.2lf", cnt, sum / cnt);
    } else {
        printf("The average of 0 numbers is Undefined");
    }
    return 0;
}