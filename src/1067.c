#include <stdio.h>
#include <string.h>
#define LEN 21

int main (void) {
    char rpwd[LEN]; // 正确密码
    char upwd[500]; // 用户输入密码
    int count;      // 可尝试次数

    scanf("%s %d", rpwd, &count);
    getchar(); // 回车挡掉

    while (1) {
        scanf("%[^\n]", upwd);
        getchar(); // 回车挡掉
        if (count == 0) {
            printf("Account locked\n");
            break; // 尝试次数为0结束
        } else if (strcmp(upwd, "#") == 0) {
            break; // 读到#结束
        } else if (strcmp(upwd, rpwd) == 0) {
            printf("Welcome in\n");
            break; // 密码正确结束
        } else {
            printf("Wrong password: %s\n", upwd);
            count--;
        }
    }

    return 0;
}
