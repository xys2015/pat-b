#include <stdio.h>

int main () {
    char input[10010];  // �����ַ���
    char one;           // ��1������
    char mid[10000];    // �м������ַ���, ������С����
    int mlen = 0;       // �м��ַ����ĳ���
    char two;           // ��2������
    int end = 0;        // ��������
    char res[20000];    // �������ս��
    int rlen;           // �������ĳ���
    int pos;            // С�����λ��
    char *ptr;
    int i;
    int temp;

    scanf("%s", input);
    one = input[0];
    ptr = input + 1;
    // ��mid[], mlen�õ�
    while (1) {
        if (*ptr == '.') {
            ptr++;
            continue;
        }
        mid[mlen] = *ptr;
        mlen++;
        ptr++;
        if (*ptr == 'E') {
            two = *(ptr + 1);
            ptr += 2; // ��ʱ��ָ���2���ź���ĵ�1������
            break;
        }
    }
    // ��end�õ�
    while (*ptr != '\0') {
        end = end * 10 + (*ptr - '0');
        ptr++;
    }

    // ���ڸ�res�������, һ����2�����
    if (two == '-') {
        res[0] = one;
        res[1] = '0';
        res[2] = '.';
        rlen = 3;
        // ��[3, end-1]�ĵط��ų�'0'
        for (i=1; i<=end-1; i++) {
            res[rlen] = '0';
            rlen++;
        }
        for (i=0; i<mlen; i++) {
            res[rlen] = mid[i];
            rlen++;
        }
    }
    if (two == '+') {
        res[0] = one;
        rlen = 1;
        pos = end + 2; // С�����λ��
        if (pos >= mlen + 1) {
        // С������ĩβ
            for (i=0; i<mlen; i++) {
                res[rlen] = mid[i];
                rlen++;
            }
            temp = rlen;
            for (i=temp; i<pos; i++) {
                res[rlen] = '0';
                rlen++;
            }
        } else {
        // С�������м�
            for (i=0; i<mlen; i++) {
                res[rlen] = mid[i];
                rlen++;
                if (rlen == pos) {
                    res[rlen] = '.';
                    rlen++;
                }
            }
        }
    }

    // ��ӡ
    for (i=0; i<rlen; i++) {
        // ���Ų���ӡ
        if (res[i] == '+') {
            continue;
        }
        printf("%c", res[i]);
    }

    return 0;
}
