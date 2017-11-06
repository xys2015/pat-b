#include <stdio.h>

struct list {
    int data;
    struct list *next;
};
typedef struct list s_list;
typedef struct list *p_list;

p_list insert (p_list p, int x);
void print (p_list head);
int del (p_list head, p_list *rear);


int main () {
    int i;
    int n;        // ����Ԫ�ظ���
    int m;        // ����λ��
    int x;        // ��ǰ��ȡ����
    p_list head;  // ͷָ��
    p_list rear;  // βָ��

    head = (s_list*)malloc(sizeof(s_list));
    head->next = NULL;
    rear = head;
    scanf("%d", &n);
    scanf("%d", &m);
    m = m % n;

    // Ϊ����ֵ
    for (i=1; i<=n; i++) {
        scanf("%d", &x);
        rear = insert(rear, x); // ��̬�޸�βָ���ָ��
    }

    // ����������ƶ�
    for (i=1; i<=m; i++) {
        x = del(head, &rear);
        insert(head, x);
    }
    print(head);

    return 0;
}

// ��pԪ�صĺ������һ��Ԫ��x
// ����ֵ: ����һ��ָ��ɾԪ�ص�ָ��
p_list insert (p_list p, int x) {
    p_list temp = (s_list*)malloc(sizeof(s_list));
    temp->data = x;
    temp->next = p->next;
    p->next = temp;
    return temp;
}

// ɾ��һ��βԪ��, ��������ֵ
// ������Ԫ�ص�һ���ڵ������ӳ������Ƴ����޴�, ֻҪ��ɾԪ��
// ��ֵ, ����������, �Ժ���ʱ�����ؽ���ɾ�ڵ�
// �ú�����Ҫ���ڲ��ı�rear��ָ��, �����Ҫ����ָ���ָ��
int del (p_list head, p_list *rear) {
    p_list pre;      // ���һ��Ԫ�ص�ǰһ��Ԫ��
    p_list tempRear; // ָ��ɾԪ��, Ҳ�������һ��Ԫ��
    int value;       // ��ɾ��Ԫ�ص�ֵ

    value = (*rear)->data; // ������������ȼ��Ŀ�
    tempRear = *rear;
    pre = head->next;
    while (pre->next != *rear) {
        pre = pre->next;
    }
    *rear = pre;
    (*rear)->next = NULL;
    free(tempRear);

    return value;
}

// ��ӡ����
void print (p_list head) {
    p_list p;
    char ch = ' '; // ��ӡ���Ʊ���

    p = head->next;
    while (p != NULL) {
        if (p->next == NULL) {
            ch = '\n';
        }
        printf("%d%c", p->data, ch);
        p = p->next;
    }
}
