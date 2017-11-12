#include <stdio.h>

int main (void) {
    int n; // 学生总数
    int s; // 要查询的学生数
    int score[101] = {0};
    int temp;
    int i;
    char ch = ' ';

    scanf("%d", &n);
    for (i=1; i<=n; i++) {
        scanf("%d", &temp);
        score[temp]++;
    }
    scanf("%d", &s);
    for (i=1; i<=s; i++) {
        scanf("%d", &temp);
        if (i == s) ch = '\n';
        printf("%d%c", score[temp], ch);
    }

    return 0;
}
