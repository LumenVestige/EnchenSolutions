//
// Created by sanenchen on 25-9-19.
//
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
pair<int, int> findMax(vector<int>& nums) {
    pair<int,int> tmp = {-1, INT_MIN};
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] > tmp.second) {
            tmp.first = i;
            tmp.second = nums[i];
        }
    }
    return tmp;
}
TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
    if (nums.size() == 0) {
        return nullptr;
    }
    auto m = findMax(nums);
    auto t = new TreeNode(m.second);
    // 分为两半
    // 左半部分
    vector<int> left;
    if (m.first > 0) {
        left.assign(nums.begin(), nums.begin() + m.first);
        t->left = constructMaximumBinaryTree(left);
    } else {
        t->left = nullptr;
    }

    vector<int> right;
    if (m.first < nums.size() - 1) {
        right.assign(nums.begin() + m.first + 1, nums.end());
        t->right=constructMaximumBinaryTree(right);
    }else {
        t->right = nullptr;
    }
    return t;
}

int main() {
    double a, b, c;
    scanf("%lf %lf", &a, &b);
    c = a * b / 2;
    printf("%g", c);
    return 0;
}
