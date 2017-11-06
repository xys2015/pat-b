#include <stdio.h>

// res[10]���˵��
// 0 1 2, ����
// 3, �ո�
// 4 5, Сʱ
// 6, :
// 7 8, ����
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
    }; // 0����23��
    char line1[61];
    char line2[61];
    char line3[61];
    char line4[61];
    char res[10];       // ����ַ���
    int posDay;         // ǰ�����ַ���, ��1����ȵ��±�
    int posHour;        // ǰ�����ַ���, ��2����ȵ��±�
    int dayFlag = 0;    // 0��ʾposDayûֵ
    int minute;         // ��ŷ���
    int i = 0;

    scanf("%s", line1);
    scanf("%s", line2);
    scanf("%s", line3);
    scanf("%s", line4);

    // ����ǰ�����ַ���, ������ں�Сʱ
    while (i < 60) {
        if (dayFlag == 0) {
            // �����Ǵ�д��ĸA-G
            if (line1[i] >= 'A' && line1[i] <= 'G') {
                // ��1�δ�д��ĸ���
                if (line1[i] == line2[i]) {
                    posDay = i;
                    dayFlag = 1;
                    //printf("1 %c\n", line1[i]);
                }
            }
        } else {
            // Сʱ���������ֻ��д��ĸA-N
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

    // Сʱ�ַ�ת����
    for (i=0; i<24; i++) {
        if (hours[i] == line1[posHour]) {
            posHour = i;
            break;  // ���break�쳣�ؼ�, ������2Сʱ
            // fuck beautiful, ��ô����ô�������ר��
            // ���˸���, �����Ҳ���
            // �Լ���������, ��� 00:00, ��֪����������
        }
    }

    // �������������ַ���, �õ�����
    // ����ַ�, �������Ǵ�дӢ����ĸ, Ҳ������СдӢ����ĸ
    i = 0;
    while (i < 60) {
        if (   (line3[i] >= 'A' && line3[i] <= 'Z')
            || (line3[i] >= 'a' && line3[i] <= 'z')
            || (line4[i] >= 'a' && line4[i] <= 'z')
            || (line4[i] >= 'A' && line4[i] <= 'Z') ) {
            if (line3[i] == line4[i]) {
                minute = i;
                break; // ֻ��Ҫ��һ��
            }
        }
        i++;
    }

    getDay(res, line1[posDay]);
    getHour(res, posHour);
    getMinute (res, minute);
    res[6] = ':';   // ֱ��д��, ûë��
    res[9] = '\0';  // �ַ���������־
    printf("%s\n", res);

    return 0;
}

// ����: ������ڵ�ʱ�䲿��
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

// Сʱ����, תСʱ�ַ���, �����뵽����ַ�����4 ,5λ����
// Сʱֻ������һλ��, ����λ��
void getHour (char res[10], int posHour) {
    int m1; // ʮλ
    int m2; // ��λ
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

// ������������Բ���, ���Կ��ǰ�res������±�
// ��Ϊ����������, �Դ�ʵ�ֺ��ϸ���������
void getMinute (char res[10], int minute) {
    int m1; // ʮλ
    int m2; // ��λ
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
����1 MON
����2 TUE
����3 WED
����4 THU
����5 FRI
����6 SAT
������ SUN

input:
3485djDkxh4hhGE
2984akDfkkkkggEdsb
s&hgsfdk
d&Hyscvnm

output:
THU 14:04
*/
