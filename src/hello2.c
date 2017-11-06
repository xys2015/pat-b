#include <stdio.h>
#include <string.h>

void removeDuplicate(char str[], int n)

int main (void) {
    char name[] = "sswqswww";
    removeDuplicate(name, 2);
    printf("%s\n", name);
    return 0;
}

void removeDuplicate(char str[], int n) {
    int len = strlen(str);
    int ascii[128] = {0};
    int p = 0;
    int i;

    for (i=0; i<len; i++) {
        if (ascii[str[i]] != n) {
            ascii[str[i]]++;
            str[p++] = str[i];
        }
    }
    str[p] = '\0';
}