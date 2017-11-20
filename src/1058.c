/*

1058. 选择题(20)

批改多选题是比较麻烦的事情，本题就请你写个程序帮助老师批改多选题，并且指出哪道题错的人最多。

输入格式：

输入在第一行给出两个正整数N（<=1000）和M（<=100），分别是学生人数和多选题的个数。

随后M行，每行顺次给出
一道题的满分值（不超过5的正整数）[1, 5]
选项个数（不少于2且不超过5的正整数）[2, 5]
正确选项个数（不超过选项个数的正整数）
所有正确选项。
注意每题的选项从小写英文字母a开始顺次排列。各项间以1个空格分隔。

最后N行，每行给出一个学生的答题情况，其每题答案格式为“
(选中的选项个数 选项1 ……)”，按题目顺序给出。
注意：题目保证学生的答题情况是合法的，即不存在选中的选项数超过实际选项数的情况。

输出格式：

按照输入的顺序给出每个学生的得分，每个分数占一行。
注意判题时只有选择全部正确才能得到该题的分数。
最后一行输出错得最多的题目的错误次数和编号（题目按照输入的顺序从1开始编号）。
如果有并列，则按编号递增顺序输出。
数字间用空格分隔，行首尾不得有多余空格。
如果所有题目都没有人错，则在最后一行输出“Too simple”。

输入样例：
学生人数  多选题个数
3 4 
满分值 选项个数 正确选项个数 所有正确选项
3 4 2 a c
2 5 1 b
5 3 2 b c
1 5 4 a b d e
选中的选项个数 选项1 ……
(2 a c)y (2 b d)n (2 a c)n (3 a b e)n
(2 a c)y (1 b)y (2 a b)n (4 a b d e)y
(2 b d)n (1 e)n (2 b c)y (4 a b c d)n
输出样例：
3 // 第1个学生的得分
6 // 第2个学生的得分
5 // 第3个学生的得分
最多错误次数  错误编号
2 2 3 4

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Ques {
    int full;    // 该题分数
    int calc;   // 正确计算分
    int error; // 该题错误次数
    // int xxgs;   // 选项个数
    // int zqxxgs; // 正确选项个数
    // char syzqxx[6]; // 所有正确选项
};
// struct Stu {

// };
typedef struct Ques ques; 
// typedef struct Stu stu;

int main (void) {
    int n;  // 学生人数
    int m; // 多选题个数
    int score[1010] = {0}; // 学生得分
    ques mxt[100]; // 每一题的信息
    int i;
    int j;
    int k;

    scanf("%d %d", &xsrs, &dxtgs);
    // 每题的信息录入
    for (i = 1; i <= dxtgs; i++) {
        dxt[i].error = 0;
        scanf("%d %d %d", &dxt[i].mfz, &dxt[i].xxgs, &dxt[i].zqxxgs);
        for (j = 1; j <= dxt[i].zqxxgs; j++) {
            scanf("%c", &(dxt[i].syzqxx[j]));
        }
        dxt[i].syzqxx[++j] = '\0';
    }
    for (i = 1; i <= dxtgs; i++) {
        printf("%d %d %d\n", dxt[i].mfz, dxt[i].xxgs, dxt[i].zqxxgs);
        printf("%s\n", dxt[i].syzqxx);
    }
    exit(1);
    // 每个学生答题情况
    int temp; // 选中选项个数
    char ch;  // 当前选择
    int isRight;
    for (i = 1; i <= xsrs; i++) {
        for (j = 1; j <= dxtgs; j++) {
            isRight = 1;
            scanf("(%d", &temp);
            if (temp != dxt[j].zqxxgs) {
                dxt[j].error++;
            } else {
                for (k = 1; k <= temp; k++) {
                    if (k != temp) {
                        scanf("%c", &ch);
                    } else {
                        scanf("%c)", &ch);
                    }    
                    if (ch != dxt[j].syzqxx[k]) {
                        dxt[j].error++;
                        isRight = 0;
                        break;
                    }
                }
                if (isRight == 1) {
                    score[i] += dxt[j].mfz;
                }
            }
        }
    }

    for (i = 1; i <= xsrs; i++) {
        printf("%d\n", score[i]);
    }

    return 0;
}
