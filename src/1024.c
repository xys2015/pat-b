#include <stdio.h>

int main () {
    char input[10010];  // 输入字符串
    char one;           // 第1个符号
    char mid[10000];    // 中间数字字符串, 不包括小数点
    int mlen = 0;       // 中间字符串的长度
    char two;           // 第2个符号
    int end = 0;        // 最后的整数
    char res[20000];    // 保存最终结果
    int rlen;           // 结果数组的长度
    int pos;            // 小数点的位置
    char *ptr;
    int i;
    int temp;

    scanf("%s", input);
    one = input[0];
    ptr = input + 1;
    // 把mid[], mlen拿到
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
            ptr += 2; // 这时候指向第2符号后面的第1个数字
            break;
        }
    }
    // 把end拿到
    while (*ptr != '\0') {
        end = end * 10 + (*ptr - '0');
        ptr++;
    }

    // 现在搞res结果数组, 一共分2种情况
    if (two == '-') {
        res[0] = one;
        res[1] = '0';
        res[2] = '.';
        rlen = 3;
        // 在[3, end-1]的地方放出'0'
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
        pos = end + 2; // 小数点的位置
        if (pos >= mlen + 1) {
        // 小数点在末尾
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
        // 小数点在中间
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

    // 打印
    for (i=0; i<rlen; i++) {
        // 正号不打印
        if (res[i] == '+') {
            continue;
        }
        printf("%c", res[i]);
    }

    return 0;
}
