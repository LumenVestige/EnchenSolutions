#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
ListNode* reverseList(ListNode* head) {
    if (head == nullptr) {
        return nullptr;
    }
    // 返回一个反转后的头指针
    // 递归 要定义好这个函数将会返回什么样的
    function<ListNode*(ListNode*)> dfs = [&](ListNode* list)-> ListNode* {
        if (list->next == nullptr) {
            return list;
        }
        ListNode* last = dfs(list->next);
        list->next->next = list;
        list->next = nullptr;
        return last;
    };
    return dfs(head);
}