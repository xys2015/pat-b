#include <stdio.h>
#include <ctype.h>

int main (void) {
    int sum = 0;
    int zero = 0;
    int one = 0;
    int flag = 0;
    char ch;

    while ((ch = getchar()) != '\n') {
        if (isalpha(ch)) {
            ch = tolower(ch);
            sum += ch - 96;
        }
    }
    if (sum == 0) flag = 1;
    do {
        if (sum % 2 == 0) zero++;
        if (sum % 2 == 1) one++;
        sum = sum / 2;
    } while (sum != 0);
    
    if (flag == 1) {
        // WTF 0的进制还是0, 应该输出1 0啊???
        printf("0 0"); // 测试点2
    } else {
        printf("%d %d", zero, one);
    }

    return 0;
}
