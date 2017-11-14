#include <stdio.h>
#include <string.h> 
 
int main (void)  {
    int num = 100;
    if (1) {
        int num = 2;
        printf("in.num: %d\n", num);
    }
    printf("out.num: %d\n", num);

    return 0;
}