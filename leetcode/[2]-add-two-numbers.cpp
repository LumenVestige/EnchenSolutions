//
// Created by sanenchen on 25-7-17.
//

#include "LeetCodes.h"

ListNode* LeetCodes::addTwoNumbers(ListNode* l1, ListNode* l2) {
    // 遍历链表 存入两个数组中
    vector<int> n1;
    vector<int> n2;
    while(l1 != nullptr) {
        n1.push_back(l1->val);
        l1 = l1->next;
    }
    while(l2 != nullptr) {
        n2.push_back(l2->val);
        l2 = l2->next;
    }

    vector<int> ans; // 结果
    // 总体的大数相加的逻辑：
    // 如果 两数之和(或者两数之和+1，进位)小于10 那么就直接相等，否则标记进位符号
    int length = max(n1.size(), n2.size()); // 最长的那个数的长度
    int carry = 0;
    for (int i = 0; i < length; i ++) {
        // 判断是否越界
        int i1, i2;
        if (i >= n1.size()) {
            i1 = 0;
            i2 = n2[i];
        } else if (i >= n2.size()) {
            i2 = 0;
            i1 = n1[i];
        } else {
            i1 = n1[i];
            i2 = n2[i];
        }
        // 正常情况
        // 相加后是否大于10
        int temp = i1 + i2 + carry;
        if (temp < 10) {
            ans.push_back(temp);
            carry = 0;
        }
        else {
            carry = temp / 10;
            ans.push_back(temp - carry * 10);
        }
    }
    if (carry != 0) {
        ans.push_back(carry);
    }
    // 输出 ans 的内容
    for (auto item : ans) {
        cout << item;  // 如果 ans 是一个容器，这里会按元素输出
    }

    // ans 转链表
    ListNode* ans_list = new ListNode();  // 创建头节点
    ListNode* root = ans_list;            // root 保持对头节点的引用

    for (auto it = ans.begin(); it != ans.end(); ++it) {
        ans_list->val = *it;  // 当前节点的值设为 item
        if (it + 1 != ans.end()) {
            ans_list->next = new ListNode();  // 如果不是最后一个节点，创建新的节点
            ans_list = ans_list->next;         // 移动到下一个节点
        }
    }
    return root;
}