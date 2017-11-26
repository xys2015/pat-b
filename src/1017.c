#include <stdio.h>

void print (char arr[], int len, int mod);

int main () {
    char a[1020];
    int b;
    char res[1020]; // 结果字符串
    int mod = 0; // 余数
    int len = 0; // 结果字符串长度(最后一位存储'\0')
    int now; // 每一次的商
    char *ptr;

    ptr = a;
    scanf("%s %d", a, &b);

    // 每次都拿到结果和余数
    while (*ptr != '\0') {
        // 想象一下草稿纸算除法, 每次"剩下"的数, 都是当前数+上一位的余数*10
        // 余数为零也不例外, 像这样 a[i] + 0 * 10
        now = (int)(*ptr - '0') + (mod * 10);
        res[len] = (char)((now / b) + '0');
        len++;
        mod = now % b;
        ptr++;
    }
    res[len] = '\0'; // 指向结果字符串最后一位 '\0'
    print(res, len, mod);

    // 本题如果不限制输出格式, 那么下面这段简单的输出就OK啦
    // printf("%s %d\n", res, mod);

    return 0;
}

void print (char arr[], int len, int mod) {
    int i;
    // 当出现0811, 这样的商, 也就0开头, 并且后面还有数
    // 我们需要对输出做特殊处理, 就是手动用putchar输出,
    // 跳过第0位, 也就是保存0的这一位
    if (len >= 2 && (*arr == '0')) {
        for (i=1; i<=len-1; i++) {
            putchar(arr[i]);
        }
        printf(" %d\n", mod);
    } else {
        printf("%s %d\n", arr, mod);
    }
}
