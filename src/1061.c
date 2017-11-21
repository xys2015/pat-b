#include <stdio.h>
#define LEN 110
int main (void) {
    int snum;
    int qnum;
    int qscore[LEN];
    int answer[LEN];
    int i;
    int j;
    int temp;
    int score;

    scanf("%d %d", &snum, &qnum);
    for (i = 0; i < qnum; i++) {
        scanf("%d", &qscore[i]);
    }
    for (i = 0; i < qnum; i++) {
        scanf("%d", &answer[i]);
    }
    // i学生, j题目
    for (i = 0; i < snum; i++) {
        score = 0;
        for (j = 0; j < qnum; j++) {
            scanf("%d", &temp);
            if (temp == answer[j]) {
                score += qscore[j];
            }
        }
        printf("%d\n", score);
    }

    return 0;
}
