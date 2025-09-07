//
// Created by sanenchen on 25-8-8.
//
#include <bits/stdc++.h>

using namespace std;

int search(vector<int> &nums, int target) {
    // 找到那个旋转点
    int tmp = nums[0];
    int point = 0, need_add = 0;
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] < tmp)
            point = i;
        tmp = nums[i];
    }
    need_add = nums.size() - point;
    //cout << need_add << endl;
    if (nums.size() == 1) {
        return (nums[0] == target) ? 0 : -1;
    }

    sort(nums.begin(), nums.end());
    // 二分查找 target
    int l = -1, r = nums.size();
    while (l + 1 < r) {
        int m = (l + r) / 2;
        if (nums[m] >= target)
            r = m;
        else l = m;
    }
    if (r < nums.size() && nums[r] == target) {
        if (r < need_add)
            return r + point;
        return r - need_add;
    }
    return -1;
}

int main() {
    vector nums = {4, 5, 6, 7, 0, 1, 2};
    cout << search(nums, 4);
    return 0;
}
