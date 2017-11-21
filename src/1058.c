#include <stdio.h>

struct Ques {
    int fscore;  // 该题分数
    int calc;    // 正确计算分
    int wnum;    // 该题错误次数
};
typedef struct Ques ques;

int main (void) {
    int snum;  // 学生人数
    int qnum;  // 题目数量
    ques qmsg[100]; // 每一题的信息
    int useless; // 没用的东西
    int rnum;    // 正确选项个数
    int i;
    int j;
    int k;
    char ch;

    scanf("%d %d", &snum, &qnum);
    for (i = 1; i <= qnum; i++) {
        qmsg[i].calc = 0;
        qmsg[i].wnum = 0;
        scanf("%d %d %d", &qmsg[i].fscore, &useless, &rnum);
        for (j = 1; j <= rnum; j++) {
            // 这里需要匹配空格
            scanf(" %c", &ch);
            // qmsg[i].calc += ch;
            qmsg[i].calc |= 1 << (ch - 'a' + 1);
        }
        // printf("qmsg[i].calc: %d\n", qmsg[i].calc);
    }

    getchar();     // 去除回车
    int score;     // 学生得分
    int tcalc = 0; // 临时计算分
    int cnum;      // 选中选项个数
    char ch2;      // 临时用
    for (i = 1; i <= snum; i++) {
        score = 0;
        j = 1; // 题目编号
        // 每次遍历一整行, 为一个学生的答题信息
        // 检测到(, 即答到了下一题
        while ((ch = getchar()) != '\n') {
            if (ch == '(') {
                scanf("%d", &cnum);
                for (k = 1; k <= cnum; k++) {
                    scanf(" %c", &ch2);
                    // tcalc += ch2;
                    tcalc |= 1 << (ch2 - 'a' + 1);
                }
                if (tcalc == qmsg[j].calc) {
                    score += qmsg[j].fscore;
                } else {
                    qmsg[j].wnum += 1;
                }
                tcalc = 0;
                j++;
            }
        }
        printf("%d\n", score);
    }

    int wmax = qmsg[1].wnum;
    for (i = 1; i <= qnum; i++) {
        if (qmsg[i].wnum > wmax) {
            wmax = qmsg[i].wnum;
        }
    }
    if (wmax == 0) {
        printf("Too simple\n");
    } else {
        printf("%d", wmax);
        for (i = 1; i <= qnum; i++) {
            if (qmsg[i].wnum == wmax) {
                // 每个空格都很关键
                printf(" %d", i, ch);
            }
        }
    }

    return 0;
}
