#include <stdio.h>

// input: 3 4 -5 2 6 1 -2 0
// output: 12 3 -10 1 6 0

int main () {
    int source[1100];     // 原多项式, 下标0不存东西
    int res[1100];        // 结果多相似, 下标0不存东西
    int slen = 0;         // 原多项式长度, 指向最后一个元素
    int rlen = 0;         // 结果多项式长度, 指向最后一个元素
    int si = 1;
    int ri = 1;
    int i;
    char isEnter = 'x';   // 初始任意非\n字符, 靠它实现, 按回车结束循环
    char ch = ' ';        // 打印控制字符

    // 读数
    while (isEnter != '\n') {
        scanf("%d", &source[si]);
        slen = slen + 1;
        si = si + 1;
        isEnter = getchar();
    }

    // 求导
    // 指数为0, 该项直接不用看了
    // 因为题目中说了, 输入是按照指数递降的方式, 那么
    // 常数项, 只可能在最后, 所以首先检查下最后一项是不是0,
    // 如果是0, 直接删掉, 也就是长度-2
    if (source[slen] == 0) {
        slen = slen - 2;
    }
    // 根据题目的含义, 输入不可能出现0 0, 但输出可能会出现
    if (slen == 0) {
        printf("0 0\n");
    }
    // 循环每次+2
    for (i=1; i<=slen; i+=2) {
        res[ri] = source[i] * source[i + 1]; // 系数
        ri = ri + 1;
        res[ri] = source[i + 1] - 1;   // 指数
        ri = ri + 1;
        rlen = rlen + 2; // 指数和系数都添加一次, 总长+2
    }

    for (i=1; i<=rlen; i++) {
        if (i == rlen) {
            ch = '\n';
        }
        printf("%d%c", res[i], ch);
    }

    return 0;
}
