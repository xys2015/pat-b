#include <stdio.h>

int main () {
    int a1 = 0;
    int a2 = 0;
    int a3 = 0;
    float a4 = 0.0; // a4�Ǹ�����
    int a5 = 0;
    int flag1 = 0; // ��Ӧ�������Ƿ�����ж�
    int flag2 = 0;
    int flag3 = 0;
    int flag4 = 0;
    int flag5 = 0;
    int time2 = 1; // �ж�a2��, ��������, ż������
    int time4 = 0; // ��¼����a4�����ĸ���, ������ƽ����
    int sum4 = 0; // ��������a4�����ĺ�
    int n; // ��������
    int i;
    int now;

    scanf("%d", &n);
    while (n != 0) {
        scanf("%d", &now);

        // A1
        if (now % 5 == 0 && now % 2 == 0) {
            flag1 = 1;
            a1 += now;
        }

        // A2
        if (now % 5 == 1) {
            flag2 = 1;
            // now��ż��, ��ȡ����
            if (time2 % 2 == 0) {
                now = -now;
            }
            time2++;
            a2 += now;
        }

        // A3
        if (now % 5 == 2) {
            flag3 = 1;
            a3 = a3 + 1;
        }

        // A4
        if (now % 5 == 3) {
            flag4 = 1;
            time4 += 1;
            sum4 += now;
        }
        a4 = (float)(sum4) / (float)(time4);

        // A5
        if (now % 5 == 4) {
            flag5 = 1;
            if (now > a5) {
                a5 = now;
            }
        }

        n = n-1;
    }

    if (flag1 == 0) {
        printf("N ");
    } else {
        printf("%d ", a1);
    }

    if (flag2 == 0) {
        printf("N ");
    } else {
        printf("%d ", a2);
    }

    if (flag3 == 0) {
        printf("N ");
    } else {
        printf("%d ", a3);
    }

    if (flag4 == 0) {
        printf("N ");
    } else {
        printf("%.1f ", a4);
    }

    if (flag5 == 0) {
        printf("N\n");
    } else {
        printf("%d\n", a5);
    }

    return 0;
}
