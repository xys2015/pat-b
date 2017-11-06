#include <stdio.h>

int isPrime (int n);

int main () {
    int pre = 3; // ����ǰһ��������ֵ
    int result = 0; // �����Ը���
    int i;
    int n;

    scanf("%d", &n); // �����n����С��5, ֱ�ӷ���0, ���������˹��ж�
    for (i=5; i<=n; i++) {
        if (isPrime(i) == 1) {
            if ((i - pre) == 2) {
                result += 1;
            }
            pre = i; // ֻҪ��ǰ��iΪ����, ���Ǿ͸���pre��ֵ
        }
    }
    printf("%d\n", result);

    return 0;
}

// �Ƿ���1, ���Ƿ���0
int isPrime (int n) {
    int i = 2;
    int flag = 1; // Ĭ��n������
    while (i * i <= n) {
        if (n % i == 0) {
            flag = 0;
            break;
        }
        i++;
    }
    return flag;
}
