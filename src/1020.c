#include <stdio.h>
#include <stdlib.h>

/*
���� ����
1�����   2�����   3����� ...
1���ۼ�   2���ۼ�   3���ۼ� ...
input:
3 20
18 15 10
75 72 45
output:
94.50
*/
struct mooncake {
    float number;
    float totalPrice;
};
typedef struct mooncake s_mk;

int compare (const void *a, const void *b);

int main () {
    int type;
    int demand;
    s_mk mk[1000];
    float now = 0;         // ��ǰʵ���������±�
    float allMoney = 0.0;  // �������
    float temp;
    int i;

    scanf("%d %d", &type, &demand);
    // Ϊ�±��ṹ�帳ֵ
    for (i=0; i<type; i++) {
        scanf("%f", &(mk[i].number));
    }
    for (i=0; i<type; i++) {
        scanf("%f", &(mk[i].totalPrice));
    }

    // ���±����� totalPrice / number, �Ӵ�С����
    // ����׬Ǯ���±�������ǰ, Ҳ����0���±괦
    qsort(mk, type, sizeof(s_mk), compare);
    for (i=0; i<type; i++) {
        // ��1�����, ����ȡ���ֿ��, �պù�
        if (now == demand) {
            break;
        }
        now += mk[i].number;
        allMoney += (float)(mk[i].totalPrice);
        // ��2�����, ��Ҫȡ���ֿ��
        if (now > demand) {
            temp = (float)(mk[i].totalPrice) / (float)(mk[i].number);
            allMoney = allMoney - ((float)(now - demand) * temp);
            break;
        }
    }
    printf("%.2f\n", allMoney);

    return 0;
}

int compare (const void *a, const void *b) {
    s_mk mk1 = *(s_mk*)a;
    s_mk mk2 = *(s_mk*)b;
    float value1 = (float)(mk1.totalPrice) / (float)(mk1.number);
    float value2 = (float)(mk2.totalPrice) / (float)(mk2.number);
    int res;

    if (value1 > value2) {
        res = -1;
    } else if (value1 < value2) {
        res = 1;
    } else {
        res = 0;
    }

    return res;
}
