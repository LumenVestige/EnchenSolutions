#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 合并两个链表 返回一个合并后的链表
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (list1 == nullptr)
        return list2;
    if (list2 == nullptr)
        return list1;
    
    ListNode* res;
    // 合并当前的
    if (list1->val <= list2->val) {
        res = list1;
        res->next = mergeTwoLists(list1->next, list2);
    } else {
        res = list2;
        res->next = mergeTwoLists(list1, list2->next);
    }
    return res;
}
