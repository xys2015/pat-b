#include <stdio.h>
struct student {
    char number[15];
    int testNo;
    int examNo;
};
typedef struct student s_stu;

int main() {
    int n;
    int m;
    s_stu stu[1010];
    int temp;
    int i;
    int j;


    scanf("%d", &n);
    for (i=0; i<n; i++) {
        scanf("%s %d %d", stu[i].number, &(stu[i].testNo), &(stu[i].examNo));
    }

    scanf("%d", &m);
    for (i=0; i<m; i++) {
        scanf("%d", &temp);
        for (j=0; j<n; j++) {
            if (stu[j].testNo == temp) {
                printf("%s %d\n", stu[j].number, stu[j].examNo);
            }
        }
    }

    return 0;
}
