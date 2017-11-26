#include <stdio.h>

// res[10]存放说明
// 0 1 2, 星期
// 3, 空格
// 4 5, 小时
// 6, :
// 7 8, 分钟
// 9, '\0'

void getDay (char str[], char ch);
void getHour (char res[10], int posHour);
void getMinute (char res[10], int minute);

int main () {
    char hours[24] = {
        '0', '1', '2', '3', '4', '5',
        '6', '7', '8', '9', 'A', 'B',
        'C', 'D', 'E', 'F', 'G', 'H',
        'I', 'J', 'K', 'L', 'M', 'N'
    }; // 0点至23点
    char line1[61];
    char line2[61];
    char line3[61];
    char line4[61];
    char res[10];       // 结果字符串
    int posDay;         // 前两个字符串, 第1次相等的下标
    int posHour;        // 前两个字符串, 第2次相等的下标
    int dayFlag = 0;    // 0表示posDay没值
    int minute;         // 存放分钟
    int i = 0;

    scanf("%s", line1);
    scanf("%s", line2);
    scanf("%s", line3);
    scanf("%s", line4);

    // 遍历前两个字符串, 解出星期和小时
    while (i < 60) {
        if (dayFlag == 0) {
            // 星期是大写字母A-G
            if (line1[i] >= 'A' && line1[i] <= 'G') {
                // 第1次大写字母相等
                if (line1[i] == line2[i]) {
                    posDay = i;
                    dayFlag = 1;
                    //printf("1 %c\n", line1[i]);
                }
            }
        } else {
            // 小时可能是数字或大写字母A-N
            if (   (line2[i] >= 'A' && line2[i] <= 'N')
                || (line2[i] >= '0' && line2[i] <= '9') ) {
                if (line1[i] == line2[i]) {
                    posHour = i;
                    //printf("2 %c\n", line1[i]);
                    break;
                }
            }
        }
        i++;
    }

    // 小时字符转数字
    for (i=0; i<24; i++) {
        if (hours[i] == line1[posHour]) {
            posHour = i;
            break;  // 这个break异常关键, 卡了我2小时
            // fuck beautiful, 怎么看怎么觉得这儿专门
            // 做了个坑, 等着我踩呢
            // 自己做个测试, 输出 00:00, 就知道坑在哪了
        }
    }

    // 遍历后面两个字符串, 拿到分钟
    // 这个字符, 即可能是大写英文字母, 也可能是小写英文字母
    i = 0;
    while (i < 60) {
        if (   (line3[i] >= 'A' && line3[i] <= 'Z')
            || (line3[i] >= 'a' && line3[i] <= 'z')
            || (line4[i] >= 'a' && line4[i] <= 'z')
            || (line4[i] >= 'A' && line4[i] <= 'Z') ) {
            if (line3[i] == line4[i]) {
                minute = i;
                break; // 只需要第一次
            }
        }
        i++;
    }

    getDay(res, line1[posDay]);
    getHour(res, posHour);
    getMinute (res, minute);
    res[6] = ':';   // 直接写死, 没毛病
    res[9] = '\0';  // 字符串结束标志
    printf("%s\n", res);

    return 0;
}

// 功能: 添加日期的时间部分
void getDay (char str[], char ch) {
    switch (ch) {
        case 'A':
            str[0] = 'M';
            str[1] = 'O';
            str[2] = 'N';
            str[3] = ' ';
            break;
        case 'B':
            str[0] = 'T';
            str[1] = 'U';
            str[2] = 'E';
            str[3] = ' ';
            break;
        case 'C':
            str[0] = 'W';
            str[1] = 'E';
            str[2] = 'D';
            str[3] = ' ';
            break;
        case 'D':
            str[0] = 'T';
            str[1] = 'H';
            str[2] = 'U';
            str[3] = ' ';
            break;
        case 'E':
            str[0] = 'F';
            str[1] = 'R';
            str[2] = 'I';
            str[3] = ' ';
            break;
        case 'F':
            str[0] = 'S';
            str[1] = 'A';
            str[2] = 'T';
            str[3] = ' ';
            break;
        case 'G':
            str[0] = 'S';
            str[1] = 'U';
            str[2] = 'N';
            str[3] = ' ';
            break;
    }
}

// 小时数字, 转小时字符串, 并插入到结果字符串中4 ,5位置中
// 小时只可能是一位数, 或两位数
void getHour (char res[10], int posHour) {
    int m1; // 十位
    int m2; // 各位
    if (posHour <= 9) {
        res[4] = '0';
        res[5] = (char)(posHour + '0');
    } else {
        m1 = (int)(posHour / 10);
        m2 = (int)(posHour % 10);
        res[4] = (char)(m1 + '0');
        res[5] = (char)(m2 + '0');
    }
}

// 这个函数复用性不好, 可以考虑把res数组的下标
// 作为参数传进来, 以此实现和上个函数复用
void getMinute (char res[10], int minute) {
    int m1; // 十位
    int m2; // 各位
    if (minute <= 9) {
        res[7] = '0';
        res[8] = (char)(minute + '0');
    } else {
        m1 = (int)(minute / 10);
        m2 = (int)(minute % 10);
        res[7] = (char)(m1 + '0');
        res[8] = (char)(m2 + '0');
    }
}

/*
星期1 MON
星期2 TUE
星期3 WED
星期4 THU
星期5 FRI
星期6 SAT
星期日 SUN

input:
3485djDkxh4hhGE
2984akDfkkkkggEdsb
s&hgsfdk
d&Hyscvnm

output:
THU 14:04
*/
