#include <stdio.h>
#include <ctype.h>

int main (void) {
    char ch;
    int max = 0;
    char maxch;
    int ascii[128] = {0};
    int i;

    while ((ch = getchar()) != '\n') {
        if (isalpha(ch)) {
            ch = tolower(ch);
            ascii[ch]++;
        }
    }

    for (i='a'; i<='z'; i++) {
        if (ascii[i] > max) {
            max = ascii[i];
            maxch = i;
        }
    }
    printf("%c %d", maxch, max);

    return 0;
}
