#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct list {
    int data;
    struct list *next;
};
typedef struct list s_list;
typedef struct list *p_list;

void readList (p_list p, int n); // Ϊp�����n��ֵ
void printList (p_list phead);   // ��ӡphead
void del (p_list p, int pos);    // ɾ��p�е�pos���ڵ�
void swap (int *x, int *y);      // ��������������ֵ
int getLength (p_list p);        // �õ�p�ĳ���
void order (p_list p);           // ��p��������
int search (p_list p, int x);    // ����, �����ҵ���λ��

/*
����:
6
3 5 6 7 8 11
���:
7 6

����:
10
88 55 2 10 3 5 6 7 8 11
���:
88 55 7 6
*/

int main () {
    int n;      // �����ʼֵ����
    int gusNum; // ��ʱ���"������"
    int pos;    // Ҫɾ����λ��
    p_list head = (s_list*)malloc(sizeof(s_list));
    p_list ptr = (s_list*)malloc(sizeof(s_list)); // ������
    head->next = NULL;

    scanf("%d", &n);
    readList(head, n);
    ptr = head->next;  // ָ���һ���ڵ�
    while (ptr != NULL) {
        gusNum = ptr->data;
        while (gusNum != 1) {
            if (gusNum % 2 == 0) {
                gusNum = gusNum / 2;
            } else {
                gusNum = ((3 * gusNum) + 1) / 2;
            }
            pos = search(head, gusNum);
            // ���pos����0, ˵���������������������, ֱ���õ�
            if (pos > 0) {
                del(head, pos);
            }
        }
        ptr = ptr->next;
    }

    order(head);
    printList(head);

    return 0;
}

// ����: pΪ����ͷ���, n����Ҫ��ֵ�ĸ���
void readList (p_list p, int n) {
    p_list temp;
    while (n) {
        temp = (s_list*)malloc(sizeof(s_list));
        scanf("%d", &temp->data);
        temp->next = p->next;
        p->next = temp;
        n--;
    }
}

// ����: pheadΪ�����ͷ���
void printList (p_list phead) {
    p_list p;
    p = phead->next;
    while (p != NULL) {
        // ���һ���ַ�, ������ո�, ����ֱ�ӻ���
        if (p->next == NULL) {
            printf("%d\n", p->data);
        } else {
            printf("%d ", p->data);
        }
        p = p->next;
    }
}

// ɾ������
// ����: p��Ҫɾ�������ͷ���, pos��ɾ����λ��
void del (p_list p, int pos) {
    p_list pre = (s_list*)malloc(sizeof(s_list)); // Ҫɾ�ڵ��ǰһ��
    p_list cur = (s_list*)malloc(sizeof(s_list)); // Ҫɾ�Ľڵ�
    int count = 1;
    pre = p;

    while (count < pos) {
        pre = pre->next;
        count++;
    }
    cur = pre->next;
    pre->next = cur->next;
    free(cur);
}

void swap (int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

// ��������дӴ�С����
// ����: pҪ���������
void order (p_list p) {
    p_list temp = (s_list*)malloc(sizeof(s_list));
    int n = getLength(p); // ������
    int i;
    int j;

    /*  ����n=5, Ҳ���ǵ���������5��Ԫ����Ҫ����
        ͨ������, ������Ҫ����˫��ѭ��. ����Ҫ���������������仯
        i = 4, j = 4
        i = 4, j = 3
        i = 4, j = 2
        i = 4, j = 1

        i = 3, j = 3
        i = 3, j = 2
        i = 3, j = 1

        i = 2, j = 2
        i = 2, j = 1

        i = 1, j = 1
        �������ѭ��, ����Ϊ��ʵ������������Ч��.
    */
    n = n - 1;
    for (i=n; i>=1; i--) {
        temp = p->next;
        for (j=i; j>=1; j--) {
            // printf("i = %d, j = %d\n", i ,j);
            if (temp->data < temp->next->data) {
                swap(&temp->data, &temp->next->data);
            }
            temp = temp->next;
        }
    }
}

// �õ������ ����
int getLength (p_list p) {
    p_list temp = (s_list*)malloc(sizeof(s_list));
    int length = 0;
    temp = p->next;
    while (temp) {
        temp = temp->next;
        length++;
    }
    return length;
}

// ����Ԫ���ڵ������е�λ��
// ����: p�����ҵ�����, xҪ���ҵ�ֵ
// ����ֵ: �ҵ������������е�һ�γ��ֵ�λ��
int search (p_list p, int x) {
    p_list temp = (s_list*)malloc(sizeof(s_list));
    int index = 1;
    temp = p->next;

    while (temp != NULL) {
        if (temp->data == x) {
            return index;
        }
        index++;
        temp = temp->next;
    }

    return -1;
}
