#include <stdio.h>
#include <stdlib.h>

int main (void) {
    int i;
    int k = 8;
    int N = 14;
    for( i=0; i<N/k; i++ ) {
        printf("%d %d\n", k*i, k*i+k-1);
    }
    for( i=k*(N/k); i<N; i++ ) {
        printf("%d\n", i); 
    }
    return 0;
}