#include <stdio.h>

int main (void) {
    int n;
    int fail1 = 0;
    int fail2 = 0;
    int call1;
    int hand1;
    int call2;    
    int hand2;
    int i;

    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d %d %d %d", &call1, &hand1, &call2, &hand2);
        // 甲败
        if (hand1 != call1 + call2 && hand2 == call1 + call2) {
            fail1++;
        }
        // 乙败
        if (hand1 == call1 + call2 && hand2 != call1 + call2) {
            fail2++;
        }
    }
    printf("%d %d", fail1, fail2);
    return 0;
}
