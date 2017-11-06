#include <stdio.h>

int main () {
    int t;
    long int a;
    long int b;
    long int c;
    int i = 0;

    scanf("%d", &t);
    while (t != 0) {
        scanf("%ld", &a);
        scanf("%ld", &b);
        scanf("%ld", &c);
        i = i + 1;
        if (a + b > c) {
            printf("Case #%d: true\n", i);
        } else {
            printf("Case #%d: false\n", i);
        }
        t = t - 1;
    }
    return 0;
}

/*
input:
4
1 2 3
2 3 4
2147483647 0 2147483646
0 -2147483648 -2147483647

output:
Case #1: false
Case #2: true
Case #3: true
Case #4: false

*/
