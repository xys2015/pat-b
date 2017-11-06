#include <stdio.h>
#include <stdlib.h>

int compare (const void *a, const void *b);
int main(void) {
    long int p;          // 给定的参数
    long int max;        // 当前所选数列的最大值
    long int min;        // 当前数列的最小值, 不一定用数列的第一项
    long int number = 0; // 最大数列长度
    long int count = 0;  // 计数器
    long int n;
    long int i;
    long int j;
    scanf("%ld %ld", &n, &p);
    long int arr[n];
    
    for (i=0; i<n; i++) {
        scanf("%ld", &arr[i]);
    }
    qsort(arr, n, sizeof(long int), compare);
    // 接下来的双层循环是解本题的核心代码
    for(i=0; i<n; i++) {
        min = arr[i];
        max = min * p;
        for(j=count; j<n; j++) {
            if(arr[j] > max) break;
            // 这种写法自动整合所有数据都小于max的情况
            if(j - i >= number) number = j - i + 1;
        }
        count = j;
        if (count > n) break;
    }
    printf("%ld\n", number);
    // printf("%ld\n", count);
	return 0;
}

// 从小到大排序
int compare (const void *a, const void *b) {
    long int arg1 = *(long int*)a;
    long int arg2 = *(long int*)b;
    return arg1 - arg2;
}
