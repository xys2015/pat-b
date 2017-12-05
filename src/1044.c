#include <stdio.h>
#include <string.h>

#define LEN 20
char unit[LEN][LEN] = {
    "tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"
};
char ten[LEN][LEN] = {
    "tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou",
};

int getUnit (char str[]);
int getTen (char str[]);

int main (void) {
    int dec = 13;   // 进制
    int n;
    char tmp[LEN];  // 存储一行字符串
    int num;        // 保存数字
    char str1[LEN]; // 火星字符串1
    char str2[LEN]; // 火星字符串2
    int i;

    scanf("%d", &n);
    getchar(); // 挡掉Enter
    for (i = 0; i < n; i++) {
    	num = 0;
        scanf("%[^\n]", tmp);
        getchar(); // 挡掉Enter
        if (tmp[0] >= '0' && tmp[0] <= '9') {
            sscanf(tmp, "%d", &num); // 从字符串里提取数字
            if (num == 0) {
                printf("tret\n");
            } else if (num < dec) {
				printf("%s\n", unit[num]);			
			} else if (num / dec != 0 && num % dec == 0) {
                printf("%s\n", ten[num / dec]);
            } else {
                printf("%s %s\n", ten[num / dec], unit[num % dec]);
            }
        } else if (strcmp(tmp, "tret") == 0) {
            printf("0\n");
        } else if (strlen(tmp) > 6) {
            sscanf(tmp, "%s %s", str1, str2);
            num += getTen(str1) * dec;
            num += getUnit(str2);
            printf("%d\n", num);
        } else {
            if (getTen(tmp) != -1) {
                num = getTen(tmp) * 13;
                printf("%d\n", num);
            } else {
                num = getUnit(tmp);
                printf("%d\n", num);
            }
        }
    }

	return 0;
}

int getTen (char str[]) {
    int i;
    for (i = 0; i < 13; i++) {
        if (strcmp(str, ten[i]) == 0) return i;
    }
    return -1;
}

int getUnit (char str[]) {
    int i;
    for (i = 0; i < 13; i++) {
        if (strcmp(str, unit[i]) == 0) return i;
    }
    return -1;
}
