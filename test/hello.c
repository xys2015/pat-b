#include <stdio.h> 
int main()  
{  
    int N;  
    int i;  
    double sum = 0.0, tmp = 0.0;  
  
//    scanf("%d", &N);  
	N = 2;
    for (i = 0; i < N; i++)  
    {  
//        scanf("%lf", &tmp);  
	tmp = i + 1;
        sum += tmp * (N-i) * (i+1);   
    }  
    printf("%.2lf\n", sum);  
  
    return 0;  
}
