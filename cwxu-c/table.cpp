#include <bits/stdc++.h>
using namespace std;

// 定义一个结构体
struct Node {
    int A;
    int B;
    Node* next; // Node* int* 意思是，Node类型的指针，代表指向下一个节点的位置。
};

Node* La, *Lb; // 两个链表的头部

Node* create(int x, int z) {
    Node *p = (Node *) malloc(sizeof(Node));
    // -> 代表是指针访问成员变量 .: 针对的是一个实体 *指针.A
    p->A = x;
    p->B = z;
    p->next = NULL;
    return p;
}

void combine() {
    Node *pa, *pb, *tail;
    pa = La->next;
    pb = Lb->next;
    tail = La;
    while (pa != NULL && pb != NULL) { // 有一个处在NULL 就停止了
        if (pa->B < pb->B) {
            tail->next = pa;
            tail = tail->next;
            pa = pa->next;
        } else if (pb->B < pa->B) {
            tail->next = pb;
            tail = tail->next;
            pb = pb->next;
        } else if (pa->B + pb->B == 0) {
            pa = pa->next;
            pb = pb->next;
        } else {
            pa->A = pa->A + pb->A;
            tail->next = pa;
            tail = tail->next;
            pa = pa->next;
            pb = pb->next;
        }
    }
    if (pa != NULL) {
        tail->next = pa;
    } else {
        tail->next = pb;
    }
}

void show(Node *l) {
    Node *p = l->next;
    while (p != NULL) {
        printf("%d,%d ", p->A, p->B);
        p = p->next;
    }
}

int main() {
    // Node *tail;
    // La = create(-1, -1); // 创建、初始化链表
    // Lb = create(-1, -1);
    // // 录入La
    // tail = La;
    // int n, m, x, z;
    // scanf("%d", &n);
    // for (int i = 0; i < n; i++) {
    //     scanf("%d%d", &x, &z);
    //     Node *t = create(x, z);
    //     tail->next = t;
    //     tail = t;
    // }
    // tail = Lb;
    // scanf("%d", &m);
    // for (int i = 0; i < m; i++) {
    //     scanf("%d%d", &x, &z);
    //     Node *t = create(x, z);
    //     tail->next = t;
    //     tail = t;
    // }
    // combine();
    // show(La);
    // free(tail);
    Node *p = create(1, 1);
    free(p);
    printf("%d", p->A);
}