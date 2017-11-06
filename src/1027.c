#include <stdio.h>

void print (int n, char ch, int maxLen);

int main (void) {
    int res[1000];
    int len = 0;    // 结果数据长度
    int leave = 0;  // 剩下没用掉的符号数
    int sum = 1;    // 符合条件数据和
    int i = 3;      // 1 情况特殊, 单独考虑
    int n;          // 给定的符号数
    char symbol;    // 要打印的符号

    scanf("%d %c", &n, &symbol);
    while ((2 * i + sum) <= n) {
        sum += 2 * i;
        res[len] = i;
        len++;
        i += 2;     
    }
    leave = n - sum;

    // 控制打印
    if (len != 0) {
        for (i=len-1; i>=0; i--) {
            print(res[i], symbol, res[len - 1]);
        }
        print(1, symbol, res[len - 1]);
        for (i=0; i<len; i++) {
            print(res[i], symbol, res[len - 1]);
        }
    } else {
    // 输入的符号只有1个的情况        
        printf("%c\n", symbol);
    }
    // 经过测试, 就算是刚好用完所有符号, 也要打印剩余
    // 符号数, 此时剩余符号数是 0 
    printf("%d\n", leave);

    return 0;
}

// n打印次数, ch打印符号, maxLen一行最大长度
void print (int n, char ch, int maxLen) {
    int i;
    int space = (maxLen - n) / 2; // 需要打印的空格数
    // 打印空格
    for (i=1; i<=space; i++) {
        printf("+");
    }
    // 打印符号
    for (i=1; i<=n; i++) {
        printf("%c", ch);
    }
    printf("\n");
}