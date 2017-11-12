#include <stdio.h>
#define LIM 1000000007
int main()
{
    unsigned int P = 0, PA = 0, PAT = 0;
    char c;
    while((c = getchar()) != '\n')
    {
        if(c == 'P')   P++;
        if(c == 'A')   PA = (PA + P) % LIM;
        if(c == 'T')   PAT = (PAT + PA) % LIM;
    }
    printf("%d\n", PAT);
    return 0;
}

// PAPA ATTP ATTT
// PAPAATTPATTT  (34)