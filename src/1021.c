#include <stdio.h>

int main () {
    char str[1000];
    int num[10] = {0};
    char *ptr = str;
    int cur;
    int i;

    scanf("%s", str);
    while (*ptr != '\0') {
        cur = *ptr - '0';
        num[cur] += 1;
        ptr++;
    }

    for (i=0; i<10; i++) {
        if (num[i] != 0) {
            printf("%d:%d\n", i, num[i]);
        }
    }

    return 0;
}
