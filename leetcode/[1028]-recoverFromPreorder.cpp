//
// Created by sanenchen on 2026/08/02.
//
// 1028. 从先序遍历还原二叉树
// https://leetcode.cn/problems/recover-a-tree-from-preorder-traversal/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Level-order build; use INT_MIN as null sentinel (matches LeetCode null).
TreeNode* buildTree(const vector<int>& a) {
    if (a.empty() || a[0] == INT_MIN) return nullptr;
    TreeNode* root = new TreeNode(a[0]);
    queue<TreeNode*> q;
    q.push(root);
    size_t i = 1;
    while (!q.empty() && i < a.size()) {
        TreeNode* node = q.front();
        q.pop();
        if (i < a.size()) {
            if (a[i] != INT_MIN) {
                node->left = new TreeNode(a[i]);
                q.push(node->left);
            }
            i++;
        }
        if (i < a.size()) {
            if (a[i] != INT_MIN) {
                node->right = new TreeNode(a[i]);
                q.push(node->right);
            }
            i++;
        }
    }
    return root;
}

void printTree(TreeNode* root) {
    if (!root) { cout << "[]" << endl; return; }
    vector<string> out;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        if (!node) { out.push_back("null"); continue; }
        out.push_back(to_string(node->val));
        q.push(node->left);
        q.push(node->right);
    }
    while (!out.empty() && out.back() == "null") out.pop_back();
    cout << "[";
    for (size_t i = 0; i < out.size(); i++) {
        if (i) cout << ",";
        cout << out[i];
    }
    cout << "]" << endl;
}

TreeNode* recoverFromPreorder(string traversal) {
    if (traversal == "") return nullptr;
    TreeNode* root = new TreeNode();
    // 下一个数字间隔了多少-
    int space = 0;
    string str = "";
    bool lock = false;
    for (auto& i : traversal) {
        if (lock && i != '-') break;
        if (i == '-') {
            if (!lock) {
                lock = true;
            }
            space++;
        }
        if (!lock)
            str += i;
    }
    // cout << "====" +str << "----" << traversal << endl;
    // 拉取第一个数字
    root->val = stoi(str);
    // 找到下一个 space * - 位置
    string test = traversal;
    for (auto& i : test) {
        if (i != '-') {
            i = '!';
        }
    }
    // cout << space;
    // if (space == 0) {
    //     return root;
    // }
    cout << test << " " << traversal << endl;
    int l = test.find("!" + string(space, '-') + "!", str.size());
    string newLeft = "", newRight = "";
    // cout << space << endl;
    if (l == string::npos) {
        newLeft = traversal.substr(str.size()+space, traversal.size() - str.size());
        // cout << "NO";
    } else {
        newLeft = traversal.substr(str.size()+space, l - str.size() - space + 1);
        newRight = traversal.substr(l+1+space, traversal.size());
    }

    cout << "--=---" << traversal << " " << newLeft << " " << newRight << endl;
    root->left = recoverFromPreorder(newLeft);
    root->right = recoverFromPreorder(newRight);
    // cout << newRight << endl;
    return root;
}

int main() {
    // 改这个数字切换官方样例：1 .. 3
    const int CASE = 2;

    string traversal;
    if (CASE == 1) {
        traversal = "1-2--3--4-5--6--7";
    } else if (CASE == 2) {
        traversal = "1-2--3---4-5--6---7";
    } else {
        traversal = "1-401--349---90--88";
    }

    printTree(recoverFromPreorder(traversal));
    return 0;
}
