#include <stdio.h>

struct student {
    char name[20];
    char no[20];
    int score;
};
typedef struct student s_student; // 最好别用结构指针, 否则老麻烦了

int main () {
    s_student high; // 最高的学生
    s_student low;  // 最低分学生
    s_student temp; // 遍历学生信息, 临时用
    int n;

    scanf("%d", &n);
    scanf("%s %s %d", high.name, high.no, &high.score);
    low = high; // 第一个数据, 作为初始值
    n--;

    while (n) {
        scanf("%s %s %d", temp.name, temp.no, &temp.score);
        if (high.score < temp.score) {
            high = temp;
        }
        if (low.score > temp.score) {
            low = temp;
        }
        n--;
    }

    printf("%s %s\n", high.name, high.no);
    printf("%s %s\n", low.name, low.no);
    return 0;
}

/*
输入:
3
Joe Math990112 89
Mike CS991301 100
Mary EE990830 95

输出:
Mike CS991301
Joe Math990112
*/
