#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Ques {
    int qscore; // 满分
    int qsnum;  // 选项个数
    int qrnum; // 正确选项个数
    int qawr[128]; // 所有正确选项
};
typedef struct Ques s_ques;
struct Wrong {
    int times; // 错误次数
    int no;    // 题目编号
    char ch;   // 选项号
};
typedef struct Wrong s_wrong;

#define LEN 120
int main (void) {
    int snum; // 学生人数
    int qnum; // 题目个数
    s_ques ques[LEN]; // 每道题的信息
    s_wrong wrong[500]; // 错误信息
    char ch;
    int i;
    int j;
    int k;

    scanf("%d %d", &snum, &qnum);
    for (i = 1; i <= qnum; i++) {
        ques[i].qawr['a'] = 0;
        ques[i].qawr['b'] = 0;
        ques[i].qawr['c'] = 0;
        ques[i].qawr['d'] = 0;
        ques[i].qawr['e'] = 0;
        scanf("%d %d %d", &ques[i].qscore, &ques[i].qsnum, &ques[i].qrnum);
        for (j = 1; j <= ques[i].qrnum; j++) {
            scanf(" %c", &ch);
            // printf("%c", ch);
            ques[i].qawr[(int)(ch)] = 1;
        }
        // printf("\n");
    }
    getchar();

    // for (i = 1; i <= qnum; i++) {
    //     for (j = 'a'; j <= 'e'; j++) {
    //         printf("%c %d\n", j, ques[i].qawr[j]);
    //     } printf("\n");
    // } exit(1);

    int len; // 初始是第1道题
    int wlen = 0; // 错误信息长度
    int mys; // 这个学生选了几个选项
    char slt; // 选中选项
    for (i = 1; i <= snum; i++) {
        double score = 0.0; // 每个学生的分数
        len = 1;
        while ((ch = getchar()) != '\n') {
            if (ch == '(') {
                int cawr[128] = {0};
                scanf("%d", &mys);
                for (j = 1; j <= mys; j++) {
                    scanf(" %c", &slt);
                    // printf("%c", slt);
                    cawr[slt] = 1;
                }

                wrong[len].times = 0;
                for (k = 'a'; k <= 'e'; k++) {
                    // printf("%c %d\n", k, cawr[k]);
                    // printf("%c %d\n", k, ques[len].qawr[k]);
                    if (cawr[k] != ques[len].qawr[k]) {
                        wrong[wlen].times++;
                        wrong[wlen].no = len;
                        wrong[wlen].ch = k;
                        wlen++;
                    }
                }
                // printf("\n\n");

                if (
                    cawr['a'] == ques[len].qawr['a'] &&
                    cawr['b'] == ques[len].qawr['b'] &&
                    cawr['c'] == ques[len].qawr['c'] &&
                    cawr['d'] == ques[len].qawr['d'] &&
                    cawr['e'] == ques[len].qawr['e']
                ) {
                    score += (double)(ques[len].qscore);
                } else if (
                    (cawr['a'] == 1 && ques[len].qawr['a'] == 0) ||
                    (cawr['b'] == 1 && ques[len].qawr['b'] == 0) ||
                    (cawr['c'] == 1 && ques[len].qawr['c'] == 0) ||
                    (cawr['d'] == 1 && ques[len].qawr['d'] == 0) ||
                    (cawr['e'] == 1 && ques[len].qawr['e'] == 0) 
                ) {
                    // 该题错误
                    // do nothing
                } else {
                    // 这里是部分正确
                    score += (double)(ques[len].qscore) / 2.0;
                }
                len++;
            }
        }
        printf("%.1f\n", score);
    }

    for (i = 0; i < wlen; i++) {
        printf(
            "i:%d times:%d no:%d ch:%c\n", 
            i, wrong[i].times, wrong[i].no, wrong[i].ch
        );
    }

    return 0;
}
