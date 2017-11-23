#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
// int arr[1 << 24];
void add ();
int main (void) {
    int n = 5;
    int arr[n];
    arr[0] = 100;
    printf("%d", arr[0]);

    return 0;
}

void add () {
    static int n = 1;
    n++;
    printf("%d", n);
}
