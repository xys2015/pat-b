#include <stdio.h>

struct student {
    char name[20];
    char no[20];
    int score;
};
typedef struct student s_student; // ��ñ��ýṹָ��, �������鷳��

int main () {
    s_student high; // ��ߵ�ѧ��
    s_student low;  // ��ͷ�ѧ��
    s_student temp; // ����ѧ����Ϣ, ��ʱ��
    int n;

    scanf("%d", &n);
    scanf("%s %s %d", high.name, high.no, &high.score);
    low = high; // ��һ������, ��Ϊ��ʼֵ
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
����:
3
Joe Math990112 89
Mike CS991301 100
Mary EE990830 95

���:
Mike CS991301
Joe Math990112
*/
