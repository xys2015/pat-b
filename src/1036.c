#include <stdio.h>

int main (void) {
    int width;
    int height;
    char ch;
    char temp;
    int i;
    int j;

    scanf("%d %c", &width, &ch);
    height = (int)(width / 2.0 + 0.5); // 注意需要用 2.0
    for (i=1; i<=height; i++) {
        for (j=1; j<=width; j++) {
            // 判断什么情况下打印空格
            if (
                (i > 1 && i < height) &&
                (j > 1 && j < width)
            ) {
                temp = ' ';
            } else {
                temp = ch;
            }
            printf("%c", temp);
        }
        printf("\n");
    }

    return 0;
}