#include <stdio.h>

int main (void) {
    int ascii[128] = {0};
    char ch;

    while ((ch = getchar()) != '\n') {
        ascii[ch]++;
    }
    while (1) {
        if (ascii['P'] != 0) {
            printf("P");
            ascii['P']--;
        }
        if (ascii['A'] != 0) {
            printf("A");
            ascii['A']--;
        }
        if (ascii['T'] != 0) {
            printf("T");
            ascii['T']--;
        }
        if (ascii['e'] != 0) {
            printf("e");
            ascii['e']--;
        }
        if (ascii['s'] != 0) {
            printf("s");
            ascii['s']--;
        }
        if (ascii['t'] != 0) {
            printf("t");
            ascii['t']--;
        }

        if (
            ascii['P'] == 0 && ascii['A'] == 0 &&
            ascii['T'] == 0 && ascii['e'] == 0 &&
            ascii['s'] == 0 && ascii['t'] == 0
        ) {
            break;
        }                        
    }

    return 0;
}
