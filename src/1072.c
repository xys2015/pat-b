#include <stdio.h>
#define LEN 10000
int main (void) {
    int n;              // 学生人数
    int m;              // 需要被查缴的物品种类数
    int k;              // 个人物品数量
    char name[10];      // 姓名缩写
    int sth[LEN] = {0}; // 存放有问题物品编号
    int pstu = 0;       // 有问题学生总人数
    int psth = 0;       // 有问题物品总人数
    int first1;         // 有问题学生累加控制
    int first2;         // 有问题物品打印控制
    int temp;
    int i;
    int j;

    scanf("%d %d", &n, &m);
    for (i = 1; i <= m; i++) {
        scanf("%d", &temp);
        sth[temp] = 1;
    }
    for (i = 1; i <= n; i++) {
        scanf("%s %d", name, &k);
        first1 = 1;
        first2 = 1;
        for (j = 1; j <= k; j++) {
            scanf("%d", &temp);
            if (sth[temp] == 1) {
                if (first1 == 1) {
                    pstu++;
                    first1 = 0;
                }
                psth++;
                if (first2 == 1) {
                    printf("%s: %04d", name, temp);
                    first2 = 0;
                } else {
                    printf(" %04d", temp);
                }
            }
        }
        if (first1 == 0) printf("\n");
    }
    printf("%d %d", pstu, psth);

    return 0;
}
