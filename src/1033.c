#include <stdio.h>
#include <string.h>
//  _  .  ,  -      + 
int isWrongKey (char wrong[], char ch);

int main (void) {
    char wrong[60];     // 错误按键字符串
    char want[100010];  // 想打出的字符串
    int len;            // 想打出字符串长度
    int i;

    gets(wrong);
    scanf("%s", want);
    len = strlen(want);
    if (strlen(wrong) == 0) {
    // 如果全部按键都正常
        printf("%s", want);
    } else {
        for (i=0; i<len; i++) {
            if (isWrongKey(wrong, want[i]) == 1) {
                printf("%c", want[i]);
            }
        }
    }
    printf("\n");
    return 0;
}

// 检查当前字符ch, 能不能打出
// 1能输出, 0不能输出
int isWrongKey (char wrong[], char ch) {
    int len = strlen(wrong);
    int type; // 2小写字母 3大写字母
    int i;

    if (ch >= 'a' && ch <= 'z') type = 2;
    if (ch >= 'A' && ch <= 'Z') type = 3;

    // 全部大写坏掉
    for (i=0; i<len; i++) {
        if (wrong[i] == '+' && type == 3) return 0;
    }
    for (i=0; i<len; i++) {
        if (wrong[i] >= 'A' && wrong[i] <= 'Z') {
            // wrong[i]大写字母, ch小写字母
            if (type == 2) {
                if (wrong[i] == (ch - 32)) return 0;
            }
            // wrong[i]大写字母, ch大写字母
            if (type == 3) {
                if (wrong[i] == ch) return 0;
            }
        } else {
            // 直接坏键
            if (wrong[i] == ch) return 0;
        }
    }
    // 其它情况, 该键打出
    return 1;
}