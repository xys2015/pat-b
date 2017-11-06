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
    int faddr;     // �׵�ַ
    int n;         // �ڵ�����
    int k;         // ��ת��λ
    s_node *nd;    // ��ͷ�ڵ㿪ʼ�ź���, ��������
    s_node *temp;  // ����Ļ�������ݴ�������
    s_node tnode;  // ��ʱ�ڵ�
    int *stnum;    // ����ԭ���ṹ������
    int *renum;    // ���淴ת������
    int relen = 0; // ��ת�����ų���
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
        temp[tnode.address] = tnode; // �ⲽ�ǳ��ؼ�, ��10����ռ�, ��;������
    }
    // ��ͷ��ַ��ʼ, ��˳��ֵ
    for (i=1; i<=n; i++) {
        nd[i] = temp[faddr];
        faddr = temp[faddr].next;
        if (faddr == -1) {
        // �ų����Ͻڵ�
            n = i;
            break;
        }
    }
    free(temp); // �ò�����
    for (i=1; i<=n; i++) {
        stnum[i] = i;
    }

    // ��ת���
    reverse(stnum, renum, k, n);
    // ���ݷ�ת������, ����nd, Ҳ���ǵ�����ӡ˳��
    for (i=1; i<=n-1; i++) {
        j = renum[i];
        x = renum[i + 1];
        printf("%05d %d %05d\n", nd[j].address, nd[j].data, nd[x].address);
    }
    // ���һ����������ӡ
    j = renum[n];
    printf("%05d %d %d\n", nd[j].address, nd[j].data, -1);

    return 0;
}

void reverse (int source[], int dest[], int k, int n) {
    int i; // iѭ��ÿ��+k
    int j; // j������ʾ��k����ѭ��
    int x; // ��ʱ����i��ֵ
    int len = 0;
    for (i=k; i<=n; i+=k) {
        x = i;
        for (j=1; j<=k; j++) {
            len++;
            dest[len] = source[x];
            x--;
        }
    }
    // ��󲻹�����, ����ĩβ
    if (i != n) {
        for (j=i-(k-1); j<=n; j++) {
            len++;
            dest[len] = source[j];
        }
    }
}
