#include <stdio.h>

struct person {
    char name[10];
    int year;
    int month;
    int day;
};
typedef struct person s_person;
int tyear = 2014;   // 今年
int tmonth = 9;     // 今月
int tday = 6;       // 今日
int maxAge = 200;   // 镇上最大年龄
int i;

int judge (s_person psn);
int compare (s_person psn1, s_person psn2);

int main (void) {
    int n;                       // 镇上总人口个数
    s_person allPeople[100000];  // 总人口
    int len = 0;         // 人口实际个数
    s_person temp;       // 临时保存人口信息
    char ch;             // 丢弃字符
    s_person youngest;   // 最年轻的人
    s_person oldest;     // 最年长的人
    scanf("%d", &n);
    for (i=1; i<=n; i++) {
        scanf(
            "%s %d%c%d%c%d",
            temp.name,
            &temp.year, &ch,
            &temp.month, &ch,
            &temp.day
        );
        if (judge(temp) == 1) {
            allPeople[len] = temp;
            len++;
        }
    }

    youngest = allPeople[0]; // 初始值
    oldest = allPeople[0];   // 初始值
    for (i=1; i<len; i++) {
        if (compare(youngest, allPeople[i]) == 1) {
            youngest = allPeople[i];
        }
        if (compare(oldest, allPeople[i]) == 2) {
            oldest = allPeople[i];
        }
    }
    
    if (len != 0) {
        printf("%d %s %s\n", len, oldest.name, youngest.name);
    } else {
    // 这块这个坑, 个人感觉意义不大, 一个人都没有输出0, 这让我如何去想
        printf("0\n");
    }
    
    return 0;
}

// 判断此人生日合不合理
// 合理返回1, 不合理返回0
int judge (s_person psn) {
    int minBirthYear = tyear - maxAge; // 最小出生年份
    // 年龄过大不合理
    if (psn.year < minBirthYear) {
        return 0;
    } else if (psn.year == minBirthYear && psn.month < tmonth) {
        return 0;
    } else if (
        psn.year == minBirthYear &&
        psn.month == tmonth &&
        psn.day < tday
    ) {
        return 0;
    } else if (psn.year > tyear) {
    // 年龄过小不合理
        return 0;
    } else if (psn.year == tyear && psn.month > tmonth) {
        return 0;
    } else if (
        psn.year == tyear &&
        psn.month == tmonth &&
        psn.day > tday
    ) {
        return 0;
    } else {
    // 其它合理情况
        return 1;
    }
}

// 判断2个人年龄相对大小(前提自然是2人生日均合理)
// 相等返回0, 第1个人年龄大返回1, 第2人年龄大返回2
// 实现思路, 排除1比2大和相等的情况, 剩下的就是1比2小
int compare (s_person psn1, s_person psn2) {
    if (psn1.year < psn2.year) {
        return 1;
    } else if (psn1.year == psn2.year && psn1.month < psn2.month) {
        return 1;
    } else if (
        psn1.year == psn2.year &&
        psn1.month == psn2.month &&
        psn1.day < psn2.day
    ) {
        return 1;
    } else if (
        psn1.year == psn2.year &&
        psn1.month == psn2.month &&
        psn1.day == psn2.day 
    ) {
        return 0;
    } else {
        return 2;
    }
}