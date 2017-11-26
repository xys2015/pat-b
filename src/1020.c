#include <stdio.h>
#include <stdlib.h>

/*
种类 需求
1库存量   2库存量   3库存量 ...
1总售价   2总售价   3总售价 ...
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
    float now = 0;         // 当前实际卖出的月饼
    float allMoney = 0.0;  // 最大收益
    float temp;
    int i;

    scanf("%d %d", &type, &demand);
    // 为月饼结构体赋值
    for (i=0; i<type; i++) {
        scanf("%f", &(mk[i].number));
    }
    for (i=0; i<type; i++) {
        scanf("%f", &(mk[i].totalPrice));
    }

    // 把月饼按照 totalPrice / number, 从大到小排序
    // 即最赚钱的月饼放在最前, 也就是0号下标处
    qsort(mk, type, sizeof(s_mk), compare);
    for (i=0; i<type; i++) {
        // 第1种情况, 无需取部分库存, 刚好够
        if (now == demand) {
            break;
        }
        now += mk[i].number;
        allMoney += (float)(mk[i].totalPrice);
        // 第2种情况, 需要取部分库存
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
