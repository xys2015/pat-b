#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

long getgcd (long a, long b); 
void prlong (long a, long b);
void compute (long a1, long b1, long a2, long b2, char op);

int main (void) {
    long a1;
    long b1;
    long a2;
    long b2;

	scanf("%ld/%ld %ld/%ld", &a1, &b1, &a2, &b2); 
    compute(a1, b1, a2, b2, '+');
    compute(a1, b1, a2, b2, '-');
    compute(a1, b1, a2, b2, '*');
    compute(a1, b1, a2, b2, '/');
    return 0;
}

long getgcd (long a, long b) {
    long r;
    while((r = a % b))
    {
        a = b;
        b = r;
	}
	
    return b;
}

void print (long a, long b) {
	if (a == 0) {
		printf("0");
		return;
	}
	
	long gcd = getgcd(a, b);
    a = a / gcd;
    b = b / gcd;
    if (a < 0) printf("(");
    if (b == 1) {
		printf("%ld", a);
	} else if (b > abs(a)) {
		printf("%ld/%ld", a, b);
	} else {
		printf("%ld %ld/%ld", a / b, abs(a) % b, b);
	}
    if(a < 0) printf(")");
}

void compute (long a1, long b1, long a2, long b2, char op) {
    long a;
    long b;
//    long gcd;
//    long lcm;

    // 化简
//    gcd = getgcd(a1, b1);
//    a1 = a1 / gcd;
//    b1 = b1 / gcd;
//    gcd = getgcd(a2, b2);
//    a2 = a2 / gcd;
//    b2 = b2 / gcd;
//    lcm = (b1 * b2) / getgcd(b1, b2);
    
    // 先打印, 避免夜长梦多
    print(a1, b1);
    printf(" %c ", op);
    print(a2, b2);
    printf(" = ");
    
    if (op == '+') {
        a = a1 * b2 + a2 * b1;
        b = b1 * b2;
    } else if (op == '-') {
        a = a1 * b2 - a2 * b1;
        b = b1 * b2;
    } else if (op == '*') {
		a = a1 * a2;
		b = b1 * b2;
	} else if (op == '/') {
		a = a1 * b2;
		b = b1 * a2;
		if (b < 0) {
			b = -b;
			a = -a;
		}
//		printf("a: %d\n", a);
//		printf("b: %d\n", b);
	}
	
    if (b == 0 && op == '/') {
        printf("Inf");
    } else {
        print(a, b);
    }
    printf("\n");
}

