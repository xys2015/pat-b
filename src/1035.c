#include <stdio.h>
#include <stdlib.h>

void swap (int *a, int *b);
int insertionSort (int arr[], int n, int midArr[]);
void mergeArray (int arr[], int left, int mid, int right);
void mergeSort (int arr[], int len, int midArr[]);
int arrCompare (int arr1[], int arr2[], int len);
void printArr (int arr[], int len);

int main (void) {
    int n;
    scanf("%d", &n);
    int *src1Arr = (int*)malloc(sizeof(int) * n); // 原始数组
    int *src2Arr = (int*)malloc(sizeof(int) * n); // 原始数组
    int *midArr = (int*)malloc(sizeof(int) * n);  // 排序中间数组
    int flag = 0; // 插入排序匹配标志
    int i;

    // 原始数组赋值
    for (i=0; i<n; i++) {
        scanf("%d", &src1Arr[i]);
        src2Arr[i] = src1Arr[i];
    }
    // 中间数组赋值
    for (i=0; i<n; i++) {
        scanf("%d", &midArr[i]);
    }

    flag = insertionSort(src1Arr, n, midArr);
    if (flag == 0) {
        mergeSort(src2Arr, n, midArr);
    }
    return 0;
}

// 插入排序
int insertionSort (int arr[], int n, int midArr[]) {
    int i;
    int j;
    int flag = 0;
    for (i=0; i<n; i++) {
        for (j=i; j>=1; j--) {
            if (arr[j - 1] > arr[j]) {
                swap(&arr[j - 1], &arr[j]);
            }
        }
        if (flag == 1) {
            printf("Insertion Sort\n");
            printArr(arr, n);
            return 1;
        }
        if (arrCompare(arr, midArr, n) == 1) {
            flag = 1;
        }
    }
    return 0;
}

// 归并排序
void mergeArray (int arr[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int m = mid;
    int n = right;
    int *temp = (int*)malloc(sizeof(int) * n);
    int k = 0;

    // 二路归并
    while (i <= m && j <= n) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }
    //  处理剩余的元素
    while (i <= m) {
        temp[k++] = arr[i++];
    }
    while (j <= n) {
        temp[k++] = arr[j++];
    }
    // 从临时数组中拷贝到目标数组
    for (i=0; i<k; i++) {
        arr[left + i] = temp[i];
    }
    free(temp);
}

void mergeSort (int arr[], int len, int midArr[]) {
    int left;
    int mid;
    int right;
    int step = 2;
    int fmid = 0;
    int flag = 0; // 匹配标志
    int i;
    while (step <= len) {
        for (i=0; i<len; i+=step) {
            left = i;
            right = i + (step - 1);
            mid = (left + right) / 2;
            if (right > len) {
                fmid = left - 1;
                continue;
            }
            mergeArray(arr, left, mid, right);
            // printf("left: %d, mid: %d, right: %d\n", left, mid, right);
        }
        if (flag == 1) {
            printf("Merge Sort\n");
            printArr(arr, len);
            return; // 程序直接结束
        }
        if (arrCompare(arr, midArr, len) == 1) {
            flag = 1;
        }
        step = step * 2;
    }
    if (fmid != 0) {
        mergeArray(arr, 0, fmid, len - 1);
    }
    if (flag == 1) {
        printf("Merge Sort\n");
        printArr(arr, len);
        return; // 程序直接结束
    }
}

// 数据交换
void swap (int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

// 数组值比较
// 相等返回1, 不相等返回0
// 根据题意, 这两个数组长度相等
int arrCompare (int arr1[], int arr2[], int len) {
    int i;
    int isEqual = 1;
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
        if (i == len-1) ch = '\n';
        printf("%d%c", arr[i], ch);
    }
}
