#include <stdio.h>
#define MOD 1000000007
int main (void) {
    long int p = 0;
    long int pa = 0;
    long int pat = 0;
    char ch;

    while ((ch = getchar()) != '\n') {
        if (ch == 'P') p++;
        if (ch == 'A') pa = (pa + p) % MOD;
        if (ch == 'T') pat = (pat + pa) % MOD;
    }
    printf("%ld", pat);
    return 0;
}
