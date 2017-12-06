#include <stdio.h>
//  https://raw.githubusercontent.com/lsdr/monokai/master/colors/monokai.vim 
// hi MatchParen ctermbg=DarkRed guibg=lightblue
#define LEN 100010
struct Node {
    int data;
    int next;
};
typedef struct Node s_node;
s_node node[LEN];

int main (void) {
    int faddr;
    int len;
    int k;
    int taddr;
    int tdata;
    int tnext;
    int first1 = 1;
    int first2 = 1;
    int first3 = 1;
    int p;
    int i;
    scanf("%d %d %d", &faddr, &len, &k);
    for (i = 0; i < len; i++) {
        scanf("%d %d %d", &taddr, &tdata, &tnext);
        node[taddr].data = tdata;
        node[taddr].next = tnext;
    }

    // 第一波遍历, 打印 < 0 的数据
    p = faddr;
    while (p != -1) {
        if (node[p].data < 0) {
            if (first1 == 1) {
                printf("%05d %d", p, node[p].data);
                first1 = 0;
            } else {
                printf(" %05d\n", p);
                printf("%05d %d", p, node[p].data);
            }
        }
        p = node[p].next;
    }

    // 第2波遍历, 打印 [0, k] 的数据
    p = faddr;
    while (p != -1) {
        if (node[p].data >= 0 && node[p].data <= k) {
            if (first1 == 0 && first2 == 1) {
                printf(" %05d\n", p);
            }
            if (first2 == 1) {
                printf("%05d %d", p, node[p].data);
                first2 = 0;
            } else {
                printf(" %05d\n", p);
                printf("%05d %d", p, node[p].data);
            }
        }
        p = node[p].next;
    }

    // 第3波遍历, 打印 > k 的数据
    p = faddr;
    while (p != -1) {
        if (node[p].data > k) {
            if (
                // 这个补刀有2种情况, 是测试点4
                (first2 == 0 && first3 == 1) ||
                (first2 == 1 && first1 == 0 && first3 == 1)
            ) {
                printf(" %05d\n", p);
            }
            if (first3 == 1) {
                printf("%05d %d", p, node[p].data);
                first3 = 0;
            } else {
                printf(" %05d\n", p);
                printf("%05d %d", p, node[p].data);
            }
        }
        p = node[p].next;
    }
    printf(" -1\n"); // 20171125 1634 第1波刷题结束!

    return 0;
}
