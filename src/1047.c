#include <stdio.h>

int main (void) {
    int n;
    int team[1001] = {0}; // 所有队伍的总分
    int tno;    // 队伍编号
    int member; // 队员
    int score;  // 队员分数
    int championScore = 0; // 冠军队伍分数
    int championTeam;      // 冠军队伍编号
    int i;

    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d-%d %d", &tno, &member, &score);
        team[tno] += score;
    }       
    for (i = 1; i <= 1000; i++) {
        if (team[i] > championScore) {
            championTeam = i;
            championScore = team[i];
        }
    }
    printf("%d %d", championTeam, championScore);

    return 0;
}
