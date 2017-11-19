#include <stdio.h>

int main (void) {
    int total;
    double lowPower;
    int day;
    int halfDay;
    int realDay;
    int maybeEmpty = 0;
    int mustEmpty = 0;
    int empty;
    double temp;
    int i;
    int j;

    scanf("%d %lf %d", &total, &lowPower, &day);
    for (i = 1; i <= total; i++) {
        scanf("%d", &realDay);
        empty = 0;
        halfDay = realDay / 2;
        for (j = 1; j <= realDay; j++) {
            scanf("%lf", &temp);
            if (temp < lowPower) {
                empty++;
            }
        }
        if (empty > halfDay) {
            if (realDay > day) {
                mustEmpty++;
            } else {
                maybeEmpty++;
            }
        }
    }
    double maybe = (double)(maybeEmpty) / total * 100.0;
    double must = (double)(mustEmpty) / total * 100.0; 
    printf("%.1f%% %.1f%%", maybe, must);

    return 0;
}
