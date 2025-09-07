//
// Created by sanenchen on 2025/9/3.
//
#include <bits/stdc++.h>
using namespace std;

double findMaxAverage(vector<int> &nums, int k) {
    double max_ans = -INT_MAX;
    // 左指针 右指针为左指针+k
    int left = 0, right = left + k;
    int sum_tmp = 0;
    for (int i = 0; i < right; ++i) {
        sum_tmp += nums[i];
    }
    while (right <= nums.size()) {
        max_ans = max(1.0 * sum_tmp / k, max_ans);
        sum_tmp -= nums[left];
        left++;
        if (right < nums.size())
            sum_tmp += nums[right];
        right++;
    }
    return max_ans;
}

int main() {
    vector<int> nums = {-1};
    cout << findMaxAverage(nums, 1);
    return 0;
}
