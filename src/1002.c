#include <stdio.h>

int main () {
    char ch;
    int num[4]; // 数组下标0, 不用
    int sum = 0;
    int i;
    char pinyin[10][20] = {
        "ling",
        "yi",
        "er",
        "san",
        "si",
        "wu",
        "liu",
        "qi",
        "ba",
        "jiu"
    };

    while ((ch = getchar()) != '\n') {
        sum += ((int)(ch) - (int)('0'));
    }
    intToArray(num, sum);

    if (num[1] == 0 && num[2] == 0) {
        printf("%s\n", pinyin[num[3]]);
    } else if (num[1] ==0 && num[2] != 0) {
        printf("%s %s\n", pinyin[num[2]], pinyin[num[3]]);
    } else {
        printf("%s %s %s\n", pinyin[num[1]], pinyin[num[2]], pinyin[num[3]]);
    }

    return 0;
}

// 整型转数组
// 参数: arr[]存放转好的数, x要转的数, x范围[0, 900)
void intToArray (int arr[], int x) {
    int m1; // 百位余数
    int m2; // 十位余数
    int m3; // 各位余数
    m1 = (int)(x / 100);
    m2 = (int)(x / 10) % 10;
    m3 = x % 10;
    arr[0] = 0; // 占个坑位
    arr[1] = m1; // printf("%d\n", arr[1]);
    arr[2] = m2; // printf("%d\n", arr[2]);
    arr[3] = m3; // printf("%d\n", arr[3]);
    // m1, m2, m3的合法取值是[0, 9]
}

/*
    测试用例:
    输入: 123456789
    输出: si wu

    输入: 123
    输出: liu
*/

// 原题: https://www.patest.cn/contests/pat-b-practise/1002
// 参考: http://www.cnblogs.com/geyang/p/6243512.html

