#include <stdio.h>

int main (void) {
    int n;
    int arr[10];
    int sum = 0;
    int i;
    int j;

    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }
    for (i = 1; i <= n - 1; i++) {
        for (j = i + 1; j <= n; j++) {
            sum += arr[i] * 10 + arr[j];
            sum += arr[j] * 10 + arr[i];
        }
    }
    printf("%d", sum);
    return 0;
}
