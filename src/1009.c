#include <stdio.h>

// input: Hello World Here I Come
// output: Come I Here World Hello

int getLength (char *str);

int main () {
    int i;
    int j = 0;              // ��ӷָ��ַ�����
    char ch = ' ';          // ��ӡ���Ʊ���
    char source[100];       // ԭ�ַ���
    char result[80][80];    // �ָ����ַ�������
    int slen;               // ԭ�ַ�������
    int rlen = 0;           // �ַ�������һά����±�

    gets(source);
    slen = getLength(source);
    for (i=0; i<slen; i++) {
        if (source[i] != ' ') {
            result[rlen][j] = source[i];
            j++;
        }
        // �������ո�ʱ, �л����¸��±�
        // ������ͷ�ж���ո�, ��ô����ֱ�ӻ��һ��������־
        // ��ͷ�ж���ո�, ֻ��Ӱ�������ĩβ������ո�
        // ����Ŀ��û��Ӱ��, �Ҿ�û�������⴦��
        // ������PAT������, Ϊ����ͨ��
        if (source[i] == ' ') {
            result[rlen][j] = '\0';
            rlen++;
            j = 0;
        }
        // �ֶ�Ϊ���һ���ַ�����ӽ�����־
        if (source[i + 1] == '\0') {
            result[rlen][j] = '\0';
        }
    }

    for (i=rlen; i>=0; i--) {
        if (i == 0) {
            ch = '\n';
        }
        printf("%s%c", result[i], ch);
    }

    return 0;
}

int getLength (char *str) {
    int i = 0;
    while (*str != '\0') {
        i++;
        str++;
    }
    return i;
}
