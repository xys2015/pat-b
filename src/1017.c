#include <stdio.h>

void print (char arr[], int len, int mod);

int main () {
    char a[1020];
    int b;
    char res[1020]; // ����ַ���
    int mod = 0; // ����
    int len = 0; // ����ַ�������(���һλ�洢'\0')
    int now; // ÿһ�ε���
    char *ptr;

    ptr = a;
    scanf("%s %d", a, &b);

    // ÿ�ζ��õ����������
    while (*ptr != '\0') {
        // ����һ�²ݸ�ֽ�����, ÿ��"ʣ��"����, ���ǵ�ǰ��+��һλ������*10
        // ����Ϊ��Ҳ������, ������ a[i] + 0 * 10
        now = (int)(*ptr - '0') + (mod * 10);
        res[len] = (char)((now / b) + '0');
        len++;
        mod = now % b;
        ptr++;
    }
    res[len] = '\0'; // ָ�����ַ������һλ '\0'
    print(res, len, mod);

    // ������������������ʽ, ��ô������μ򵥵������OK��
    // printf("%s %d\n", res, mod);

    return 0;
}

void print (char arr[], int len, int mod) {
    int i;
    // ������0811, ��������, Ҳ��0��ͷ, ���Һ��滹����
    // ������Ҫ����������⴦��, �����ֶ���putchar���,
    // ������0λ, Ҳ���Ǳ���0����һλ
    if (len >= 2 && (*arr == '0')) {
        for (i=1; i<=len-1; i++) {
            putchar(arr[i]);
        }
        printf(" %d\n", mod);
    } else {
        printf("%s %d\n", arr, mod);
    }
}
