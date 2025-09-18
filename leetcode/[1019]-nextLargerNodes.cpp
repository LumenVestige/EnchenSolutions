#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

vector<int> nextLargerNodesLeftToRight(ListNode* head) {
    stack<pair<int, int>> st; // 这是一个todolist 前面一个是
    int current = 0;
    vector<int> ans;
    // for (int i = 0; i < nums.size(); ++i) {
    //     int t = nums[i];
    //     while (!st.empty() && t > nums[st.top()]) {
    //         ans[st.top()] = nums[st.top()];
    //         st.pop();
    //     }
    //     st.push(i);
    // }
    while (head != nullptr) {
        int t = head->val;
        while (!st.empty() && t > st.top().first) {
            ans[st.top().second] = t;
            st.pop();
        }
        st.emplace(t, current);
        current++;
        ans.push_back(0);
        head = head->next;
    }
    return ans;
}

// 从右向左
vector<int> nextLargerNodes(ListNode* head) {
    // 链表转vector
    vector<int> nums;
    while (head != nullptr) {
        nums.push_back(head->val);
        head = head->next;
    }
    stack<int> st; // 这是一个todolist
    vector<int> ans(nums.size(), 0);
    for (int i = nums.size() - 1; i >= 0; --i) {
        int t = nums[i];
        while (!st.empty() && t >= nums[st.top()]) {
            st.pop();
        }
        if (!st.empty())
            ans[i] = nums[st.top()];
        st.push(i);
    }
    return ans;
}