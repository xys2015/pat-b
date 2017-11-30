#include <stdio.h>

int isPrime (int n);

int main (void) {
	int n;
	int i;
	int count = 0;

	scanf("%d", &n);
	for (i = 5; i <= n; i++) {
		if (isPrime(i) && isPrime(i - 2)) count++;
	}
	printf("%d", count);

	return 0;
}

// yes 1, no 0
int isPrime (int n) {
	int i;
	for (i = 2; i * i <= n; i++) {
		if (n % i == 0) return 0;
	}
	return 1;
}
