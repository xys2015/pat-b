#include <stdio.h>

// GSK 1G = 493K, 1S = 29K
#define SK 29
#define GK 493

void formatMoney (int k);

int main (void) {
    int pg;
    int ps;
    int pk;
    int pksum;
    int ag;
    int as;
    int ak;
    int aksum;
    char t;

    scanf("%d%c%d%c%d", &pg, &t, &ps, &t, &pk);
    scanf("%d%c%d%c%d", &ag, &t, &as, &t, &ak);
    pksum = pg * GK + ps * SK + pk;
    aksum = ag * GK + as * SK + ak;
    formatMoney(aksum - pksum);

    return 0;
}

// 钱格式化显示
void formatMoney (int k) {
    int fk; // 不带符号的k
    if (k < 0) fk = -k;
    else fk = k;
    int g = fk / GK;
    int s = (fk - g * GK) / SK;
    fk = fk - (g * GK) - (s * SK);
    if (k < 0) {
        printf("-%d.%d.%d", g, s, fk);
    } else {
        printf("%d.%d.%d", g, s, fk);
    }
}