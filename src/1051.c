#include <stdio.h>
#include <math.h>

int main (void) {
    double R1;
    double P1;
    double A1;
    double B1;
    double A;
    double R2;
    double P2;
    double A2;
    double B2;
    double B;

    scanf("%lf %lf %lf %lf", &R1, &P1, &R2, &P2);
    A1 = R1 * cos(P1);
    B1 = R1 * sin(P1);
    A2 = R2 * cos(P2);
    B2 = R2 * sin(P2);
    A = A1 * A2 - B1 * B2;
    B = A1 * B2 + A2 * B1;
    if(A > -0.005 && A < 0) A = 0; // (-0.005, 0)
    if(B > -0.005 && B < 0) B = 0; // (-0.005, 0)
    printf("%.2f%+.2fi", A, B);
    
    return 0;
}
