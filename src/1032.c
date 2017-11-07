#include <stdio.h>

int main (void) {
    int n;
    int stu[100001] = {0};
    int no;
    int score;
    int maxNo;
    int maxScore = 0;
    int i;

    scanf("%d", &n);
    for (i=1; i<=n; i++) {
        scanf("%d %d", &no, &score);
        stu[no] += score;
        if (stu[no] > maxScore) {
            maxScore = stu[no];
            maxNo = no;
        }
    }
    printf("%d %d\n", maxNo, maxScore);

    return 0;
}