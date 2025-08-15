//
// Created by sanenchen on 25-8-15.
//
#include <bits/stdc++.h>
using namespace std;


// 前缀和 和 二分查找
vector<int> answerQueries(vector<int> &nums, vector<int> &queries) {
    sort(nums.begin(), nums.end());
    for (int i = 1; i < nums.size(); ++i) {
        nums[i] = nums[i - 1] + nums[i];
    }
    auto search = [&](int target) -> int {
        int left = -1, right = nums.size();
        while (left + 1 != right) {
            int mid = left + (right - left) / 2;
            if (mid < nums.size() && nums[mid] >= target)
                right = mid;
            else left = mid;
        }
        return right;
    };
    vector<int> ans;
    for (auto &it: queries) {
        int tmp = search(it);
        if (nums[tmp] == it)
            ans.push_back(tmp + 1);
        else ans.push_back(tmp);
    }
    return ans;
}

int main() {
    vector<int> nums = {2,3,4,5};
    vector<int> queries = {5};
    for (auto &it: answerQueries(nums, queries)) {
        cout << it << " ";
    }
    return 0;
}
