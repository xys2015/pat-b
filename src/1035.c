#include <stdio.h>
#include <stdlib.h>

int compare (const void *a, const void *b);
void printArr (int arr[], int len);
void mysort (int arr[], int start, int end);
int compareArr (int arr1[], int arr2[], int len);

int main (void) {
    int n;
    int srcArr[101];
    int midArr[101];
    int flag = 0;      // 归并到位标志
    int leftFirst = 0; // 不够分组的元素中第一个元素
    int i;
    int j = 0;
    int k = 0;

    scanf("%d", &n);
    for (i=0; i<n; i++) {
        scanf("%d", &srcArr[i]);
    }
    for (i=0; i<n; i++) {
        scanf("%d", &midArr[i]);
    }

    // 前半部分有序而后半部分未动为插入排序
    for (i=0; i<n; i++) {
        if (midArr[i] < midArr[i + 1]) {
            j++;
        } else {
            break;
        }
    }
    k = j + 1; // 指向第一个无序元素
    i++;
    j++;
    while (i < n) {
        if (midArr[i] == srcArr[j]) {
            i++;
            j++;
        } else {
            break;
        }
    }

    if (i == j && i == n) {
        printf("Insertion Sort\n");
        mysort(midArr, 0, k);
        printArr(midArr, n);
    } else {
        flag = 1;
        k = 2;
        while (flag && k <= n) {
            if (compareArr(srcArr, midArr, n) == 1) {
                flag = 0; // 匹配成功, 再执行一次停止
            } else {
                flag = 1;
            }
            for (i=0; i<(int)(n/k); i++) {
                mysort(srcArr, k * i, k * i + (k - 1));
            }
            leftFirst = k * (int)(n / k);
            if (leftFirst < n - 1) {
                mysort(srcArr, leftFirst, n - 1);
            }
            k = k * 2;
        }
        // if (flag != 0) {
        //     mysort(srcArr, 0, n - 1);
        // }
        printf("Merge Sort\n");
        printArr(srcArr, n);
    }

    return 0;
}

/*
功能: 对给定数组区间进行排序 (闭区间)
参数: 
    arr, 待排序的数组
    start, 起始下标
    end, 终止下标
*/
void mysort (int arr[], int start, int end) {
    int num = end - start + 1;
    qsort(&arr[start], end - start + 1, sizeof(int), compare);
}

int compare (const void *a, const void *b) {
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;
    return arg1 - arg2;
}

// 数组相等比较, 相等返回1, 不相等返回0
// 两个数组长度都为len
int compareArr (int arr1[], int arr2[], int len) {
    int isEqual = 1;
    int i;
    for (i=0; i<len; i++) {
        if (arr1[i] != arr2[i]) {
            isEqual = 0;
        }
    }
    return isEqual;
}

// 打印
void printArr (int arr[], int len) {
    int i;
    char ch = ' ';
    for (i=0; i<len; i++) {
        if (i == len - 1) ch = '\n';
        printf("%d%c", arr[i], ch);
    }
}
