#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 10010

struct Class {
    char name[10];
    int height;
};
typedef struct Class class;
int compare (const void *a, const void *b);
int main (void) {
    int zrs;        // 总人数
    int zps;        // 总排数
    int gprs;       // 该排人数
    int midpos;     // 中间位置
    class src[LEN]; // 下标0不用
    class dest[LEN];
    int i;

    scanf("%d %d", &zrs, &zps);
    for (i = 1; i <= zrs; i++) {
        scanf("%s %d", src[i].name, &src[i].height);
    }
    qsort(src + 1, zrs, sizeof(class), compare);

    int startpos = 1; // 开始位置
    int j;
    int left;      // 插入左边
    int right;     // 插入右边
    int leftpos;   // 左位置
    int rightpos;  // 右位置
    for (i = 1; i <= zps; i++) {
        if (i == 1) {
            gprs = (zrs / zps) + (zrs % zps);
        } else {
            gprs = zrs / zps;
        }
        midpos = gprs / 2 + 1;
        dest[midpos] = src[startpos];
        left = 1;
        right = 0;
        leftpos = midpos;
        rightpos = midpos;
        // 每次一段段的循环该排人数
        // 把该排人的位置调整后放入 dest 中
        for (j = startpos + 1; j <= startpos + gprs - 1; j++) {
            if (left == 1) {
                dest[--leftpos] = src[j];
                left = 0;
                right = 1;
            } else if (right == 1) {
                dest[++rightpos] = src[j];
                left = 1;
                right = 0;                
            }
        }
        char ch = ' ';
        for (j = 1; j <= gprs; j++) {
            if (j == gprs) ch = '\n';
            printf("%s%c", dest[j].name, ch);
        }
        startpos += gprs;
    }

    return 0;
}

int compare (const void *a, const void *b) {
    class arg1 = *(class*)a;
    class arg2 = *(class*)b;

    if (arg1.height != arg2.height) {
        return arg2.height - arg1.height;
    } else {
        return strcmp(arg1.name, arg2.name);
    }
}
