#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main (void) {
    char ch = 'a';
    int n = (int)(ch);
    printf("%d", n + 8);
    return 0;
}