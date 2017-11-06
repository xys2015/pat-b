#include <stdio.h>
#include <string.h>

char toUpperCase (char ch);

int main (void) {
    char should[100] = {'\0'}; // 初始化成其它不可能出现的值也可以
    char real[100] = {'\0'};
    int ascii[128] = {0}; // 初始所有字符出现字数均为0  
    int pid = 0; // 指向实际输入字符串
    int slen;
    int i;

    scanf("%s", should);
    scanf("%s", real);
    slen = strlen(should);
    for (i=0; i<slen; i++) {
        if (should[i] == real[pid]) {
            pid++;
        } else {
        // 这时候该字符就是坏键
        // 但是还需要考虑, 该键是否已经出现过
        // 如果该键是小写, 则先转为大写
            should[i] = toUpperCase(should[i]);
            if (ascii[should[i]] == 0) {
                ascii[should[i]] = 1;
                printf("%c", should[i]);
            }
        }
    }
    printf("\n");
    return 0;
}

// 小写字符转大写
// 若果本身不是小写字母, 则直接返回
char toUpperCase (char ch) {
    if (ch >= 'a' && ch <= 'z') {
        ch = ch - 32;
    }
    return ch;
}