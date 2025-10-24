#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
// 优先队列 小顶堆
ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.size() == 0) {
        return nullptr;
    }
    ListNode* virtualHead = new ListNode(0);
    ListNode* current = virtualHead;
    auto compare = [](ListNode* a, ListNode* b)->bool {
        return a->val > b->val; 
    };
    priority_queue<ListNode*, vector<ListNode*>, decltype(compare)> pq(compare);
    // 将几个头放进去
    for (auto& i : lists) {
        if (i != nullptr)
            pq.push(i);
    }
    while (!pq.empty()) {
        // 取一个堆上最小的
        auto heapTop = pq.top();
        pq.pop();
        current->next = heapTop;
        if (heapTop->next != nullptr) {
            pq.push(heapTop->next);
        }
        current = current->next;
    }
    return virtualHead->next;
}
