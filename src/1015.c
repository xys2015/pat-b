#include <stdio.h>
#include <stdlib.h>

struct student {
    long int no;
    int rp;
    int sk;
    int level;
};
typedef struct student s_stu;

void print (s_stu stu[], int len);
int compare (const void *a, const void *b);

int main () {
    int total;
    int low;
    int high;
    int len = 0;
    s_stu temp;
    int i;

    scanf("%d", &total);
    scanf("%d", &low);
    scanf("%d", &high);
    s_stu stu[total];

    for (i=0; i<total; i++) {
        scanf("%ld", &temp.no);
        scanf("%d", &temp.rp);
        scanf("%d", &temp.sk);
        if (temp.rp < low || temp.sk < low) {
            continue;
        }
        if (temp.rp >= high && temp.sk >= high) {
            temp.level = 1;
        } else if (temp.rp >= high && temp.sk < high) {
            temp.level = 2;
        } else if (temp.rp < high && temp.sk < high
            && temp.rp >= temp.sk) {
            temp.level = 3;
        } else {
            temp.level = 4;
        }
        stu[len] = temp;
        len = len + 1;
    }

    qsort(stu, len, sizeof(s_stu), compare);
    print(stu, len);

    return 0;
}

int compare (const void *a, const void *b) {
    s_stu stu1 = *((const s_stu*)a);
    s_stu stu2 = *((const s_stu*)b);
    int res;
    int sum1 = stu1.rp + stu1.sk;
    int sum2 = stu2.rp + stu2.sk;

    if (stu1.level > stu2.level) res = 1;
    if (stu1.level < stu2.level) res = -1;
    if (stu1.level == stu2.level) {
        res == 0;
        if (sum1 > sum2) res = -1;
        if (sum1 < sum2) res = 1;
        if (sum1 == sum2) {
            if (stu1.rp > stu2.rp) res = -1;
            if (stu1.rp < stu2.rp) res = 1;
            if (stu1.rp == stu2.rp) {
                if (stu1.no > stu2.no) res = 1;
                if (stu1.no < stu2.no) res = -1;
            }
        }
    }

    return res; // MD, 忘记个return, 用了我3h+, 才解决 WTF
}

void print (s_stu stu[], int len) {
    int i;

    printf("%d\n", len);
    for (i=0; i<len; i++) {
        printf("%ld %d %d\n", stu[i].no, stu[i].rp, stu[i].sk);
    }
}
