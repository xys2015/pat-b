#include <stdio.h>
#include <math.h>

int main (void) {
    double n;
    int m;
    double sum = 0.0;
    int i;
    
	scanf("%lf %d", &n, &m);
	for (i = 1; i <= m; i++) {
		sum += n;
		n = sqrt(n);
	}
	printf("%.2f\n", sum);

    return 0;
}
