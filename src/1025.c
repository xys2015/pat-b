#include <stdio.h>
#include <stdlib.h>

struct node {
    int address;
    int data;
    int next;
};
typedef struct node s_node;

void reverse (int source[], int dest[], int k, int n);

int main () {
    int faddr;     // 首地址
    int n;         // 节点总数
    int k;         // 反转单位
    s_node *nd;    // 从头节点开始排好序, 存在这里
    s_node *temp;  // 从屏幕读入数据存入这里
    s_node tnode;  // 临时节点
    int *stnum;    // 保存原来结构体的序号
    int *renum;    // 保存反转后的序号
    int relen = 0; // 反转后的序号长度
    int i;
    int j;
    int x;

    scanf("%d %d %d", &faddr, &n, &k);
    nd = (s_node*)malloc(sizeof(s_node) * 100010);
    temp = (s_node*)malloc(sizeof(s_node) * 100010);
    renum = (int*)malloc(sizeof(int) * (n + 1));
    stnum = (int*)malloc(sizeof(int) * (n + 1));

    for (i=1; i<=n; i++) {
        scanf("%d %d %d", &tnode.address, &tnode.data, &tnode.next);
        temp[tnode.address] = tnode; // 这步非常关键, 开10万个空间, 用途就在这
    }
    // 从头地址开始, 按顺序赋值
    for (i=1; i<=n; i++) {
        nd[i] = temp[faddr];
        faddr = temp[faddr].next;
        if (faddr == -1) {
        // 排除报废节点
            n = i;
            break;
        }
    }
    free(temp); // 用不到了
    for (i=1; i<=n; i++) {
        stnum[i] = i;
    }

    // 反转序号
    reverse(stnum, renum, k, n);
    // 根据反转后的序号, 调整nd, 也就是调整打印顺序
    for (i=1; i<=n-1; i++) {
        j = renum[i];
        x = renum[i + 1];
        printf("%05d %d %05d\n", nd[j].address, nd[j].data, nd[x].address);
    }
    // 最后一个数单独打印
    j = renum[n];
    printf("%05d %d %d\n", nd[j].address, nd[j].data, -1);

    return 0;
}

void reverse (int source[], int dest[], int k, int n) {
    int i; // i循环每次+k
    int j; // j用来表示有k层内循环
    int x; // 临时保存i的值
    int len = 0;
    for (i=k; i<=n; i+=k) {
        x = i;
        for (j=1; j<=k; j++) {
            len++;
            dest[len] = source[x];
            x--;
        }
    }
    // 最后不够的数, 加入末尾
    if (i != n) {
        for (j=i-(k-1); j<=n; j++) {
            len++;
            dest[len] = source[j];
        }
    }
}
