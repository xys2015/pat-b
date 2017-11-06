#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct list {
    int data;
    struct list *next;
};
typedef struct list s_list;
typedef struct list *p_list;

void readList (p_list p, int n); // 为p随机赋n个值
void printList (p_list phead);   // 打印phead
void del (p_list p, int pos);    // 删除p中第pos个节点
void swap (int *x, int *y);      // 交换两个变量的值
int getLength (p_list p);        // 得到p的长度
void order (p_list p);           // 对p进行排序
int search (p_list p, int x);    // 查找, 返回找到的位置

/*
输入:
6
3 5 6 7 8 11
输出:
7 6

输入:
10
88 55 2 10 3 5 6 7 8 11
输出:
88 55 7 6
*/

int main () {
    int n;      // 链表初始值个数
    int gusNum; // 临时存放"猜想数"
    int pos;    // 要删的数位置
    p_list head = (s_list*)malloc(sizeof(s_list));
    p_list ptr = (s_list*)malloc(sizeof(s_list)); // 遍历用
    head->next = NULL;

    scanf("%d", &n);
    readList(head, n);
    ptr = head->next;  // 指向第一个节点
    while (ptr != NULL) {
        gusNum = ptr->data;
        while (gusNum != 1) {
            if (gusNum % 2 == 0) {
                gusNum = gusNum / 2;
            } else {
                gusNum = ((3 * gusNum) + 1) / 2;
            }
            pos = search(head, gusNum);
            // 如果pos大于0, 说明序列中这个数被覆盖了, 直接拿掉
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

// 参数: p为链表头结点, n是需要赋值的个数
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

// 参数: phead为链表的头结点
void printList (p_list phead) {
    p_list p;
    p = phead->next;
    while (p != NULL) {
        // 最后一个字符, 不输出空格, 而是直接换行
        if (p->next == NULL) {
            printf("%d\n", p->data);
        } else {
            printf("%d ", p->data);
        }
        p = p->next;
    }
}

// 删除操作
// 参数: p是要删除链表的头结点, pos是删除的位置
void del (p_list p, int pos) {
    p_list pre = (s_list*)malloc(sizeof(s_list)); // 要删节点的前一个
    p_list cur = (s_list*)malloc(sizeof(s_list)); // 要删的节点
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

// 对链表进行从大到小排序
// 参数: p要排序的链表
void order (p_list p) {
    p_list temp = (s_list*)malloc(sizeof(s_list));
    int n = getLength(p); // 链表长度
    int i;
    int j;

    /*  假如n=5, 也就是单链表中有5个元素需要排序
        通过分析, 我们需要的是双层循环. 我需要变量像下面这样变化
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
        我下面的循环, 就是为了实现如上所述的效果.
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

// 得到链表的 长度
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

// 查找元素在单链表中的位置
// 参数: p待查找的链表, x要查找的值
// 返回值: 找到返回在链表中第一次出现的位置
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
