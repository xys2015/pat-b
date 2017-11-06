#include <stdio.h>

// input: Hello World Here I Come
// output: Come I Here World Hello

int getLength (char *str);

int main () {
    int i;
    int j = 0;              // 添加分割字符串用
    char ch = ' ';          // 打印控制变量
    char source[100];       // 原字符串
    char result[80][80];    // 分割后的字符串数组
    int slen;               // 原字符串长度
    int rlen = 0;           // 字符串数组一维最后下标

    gets(source);
    slen = getLength(source);
    for (i=0; i<slen; i++) {
        if (source[i] != ' ') {
            result[rlen][j] = source[i];
            j++;
        }
        // 当遇到空格时, 切换到下个下标
        // 若果开头有多个空格, 那么这里直接会存一个结束标志
        // 开头有多个空格, 只会影响输出的末尾多输出空格
        // 对题目答案没有影响, 我就没有做特殊处理
        // 本题在PAT测试上, 为满分通过
        if (source[i] == ' ') {
            result[rlen][j] = '\0';
            rlen++;
            j = 0;
        }
        // 手动为最后一个字符串添加结束标志
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
