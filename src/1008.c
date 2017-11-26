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
    int n;        // 链表元素个数
    int m;        // 右移位数
    int x;        // 当前读取的数
    p_list head;  // 头指针
    p_list rear;  // 尾指针

    head = (s_list*)malloc(sizeof(s_list));
    head->next = NULL;
    rear = head;
    scanf("%d", &n);
    scanf("%d", &m);
    m = m % n;

    // 为链表赋值
    for (i=1; i<=n; i++) {
        scanf("%d", &x);
        rear = insert(rear, x); // 动态修改尾指针的指向
    }

    // 对链表进行移动
    for (i=1; i<=m; i++) {
        x = del(head, &rear);
        insert(head, x);
    }
    print(head);

    return 0;
}

// 在p元素的后面插入一个元素x
// 返回值: 返回一个指向被删元素的指针
p_list insert (p_list p, int x) {
    p_list temp = (s_list*)malloc(sizeof(s_list));
    temp->data = x;
    temp->next = p->next;
    p->next = temp;
    return temp;
}

// 删除一个尾元素, 并返回其值
// 把链表元素的一个节点整个从程序中移除并无大碍, 只要被删元素
// 的值, 被保存下来, 以后随时可以重建被删节点
// 该函数需要在内部改变rear的指向, 因此需要定义指针的指针
int del (p_list head, p_list *rear) {
    p_list pre;      // 最后一个元素的前一个元素
    p_list tempRear; // 指向被删元素, 也就是最后一个元素
    int value;       // 被删除元素的值

    value = (*rear)->data; // 又是运算符优先级的坑
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

// 打印链表
void print (p_list head) {
    p_list p;
    char ch = ' '; // 打印控制变量

    p = head->next;
    while (p != NULL) {
        if (p->next == NULL) {
            ch = '\n';
        }
        printf("%d%c", p->data, ch);
        p = p->next;
    }
}
