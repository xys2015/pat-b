#include <stdio.h>
#include <string.h>

int main (void) {
    // elo nov
    char str[20] = "hello world";
    char res1[20];
    char res2[20];
    int suc;

    suc = sscanf(str, "%s %s", res1, res2);
    printf("suc: %d\n", suc);
    printf("res1: %s\n", res1);
    printf("res2: %s\n", res2);
    printf("r1len: %d\n", strlen(res1));
    printf("r2len: %d\n", strlen(res2));
    
   return(0);
}
