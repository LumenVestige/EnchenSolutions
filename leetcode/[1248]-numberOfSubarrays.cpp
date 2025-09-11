//
// Created by sanenchen on 25-9-10.
//
#include <bits/stdc++.h>
using namespace std;

int numberOfSubarrays(vector<int> &nums, int k) {
    auto solve = [&](int mK) -> int {
        int left = 0, oddCnt = 0, ans = 0;
        for (int right = 0; right < nums.size(); right++) {
            // 越长越合法
            oddCnt += (nums[right] % 2 != 0) ? 1 : 0;
            // 直到不合法
            while (oddCnt >= mK) {
                oddCnt -= (nums[left] % 2 != 0) ? 1 : 0;
                left++;
            }
            ans += left;
        }
        return ans;
    };
    return solve(k) - solve(k + 1);
}

int main() {
    vector<int> nums = {1,1,2,1,1};
    cout << numberOfSubarrays(nums, 3);
    return 0;
}
