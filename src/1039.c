#include <stdio.h>
#include <string.h>

int main (void) {
    char have[1010];
    int hlen;
    int h[128] = {0}; // 对应128种颜色, 实际不需要这么多
    char want[1010];
    int wlen;
    int w[128] = {0};
    int more = 0; // 多余多少珠子
    int less = 0; // 缺少多少珠子
    int temp;
    int i;

    scanf("%s", have);
    scanf("%s", want);
    hlen = strlen(have);
    wlen = strlen(want);
    for (i=0; i<hlen; i++) {
        h[have[i]]++;
    }
    for (i=0; i<wlen; i++) {
        w[want[i]]++;
    }

    for (i=0; i<128; i++) {
        temp = h[i] - w[i];
        if (temp > 0) {
            more += temp;
        } else if (temp < 0) {
            less += temp;
        }
    }

    if (less < 0) {
        printf("No %d\n", -less);
    } else {
        printf("Yes %d\n", more);
    }

    return 0;
}