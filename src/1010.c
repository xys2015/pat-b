#include <stdio.h>

// input: 3 4 -5 2 6 1 -2 0
// output: 12 3 -10 1 6 0

int main () {
    int source[1100];     // ԭ����ʽ, �±�0���涫��
    int res[1100];        // ���������, �±�0���涫��
    int slen = 0;         // ԭ����ʽ����, ָ�����һ��Ԫ��
    int rlen = 0;         // �������ʽ����, ָ�����һ��Ԫ��
    int si = 1;
    int ri = 1;
    int i;
    char isEnter = 'x';   // ��ʼ�����\n�ַ�, ����ʵ��, ���س�����ѭ��
    char ch = ' ';        // ��ӡ�����ַ�

    // ����
    while (isEnter != '\n') {
        scanf("%d", &source[si]);
        slen = slen + 1;
        si = si + 1;
        isEnter = getchar();
    }

    // ��
    // ָ��Ϊ0, ����ֱ�Ӳ��ÿ���
    // ��Ϊ��Ŀ��˵��, �����ǰ���ָ���ݽ��ķ�ʽ, ��ô
    // ������, ֻ���������, �������ȼ�������һ���ǲ���0,
    // �����0, ֱ��ɾ��, Ҳ���ǳ���-2
    if (source[slen] == 0) {
        slen = slen - 2;
    }
    // ������Ŀ�ĺ���, ���벻���ܳ���0 0, ��������ܻ����
    if (slen == 0) {
        printf("0 0\n");
    }
    // ѭ��ÿ��+2
    for (i=1; i<=slen; i+=2) {
        res[ri] = source[i] * source[i + 1]; // ϵ��
        ri = ri + 1;
        res[ri] = source[i + 1] - 1;   // ָ��
        ri = ri + 1;
        rlen = rlen + 2; // ָ����ϵ�������һ��, �ܳ�+2
    }

    for (i=1; i<=rlen; i++) {
        if (i == rlen) {
            ch = '\n';
        }
        printf("%d%c", res[i], ch);
    }

    return 0;
}
