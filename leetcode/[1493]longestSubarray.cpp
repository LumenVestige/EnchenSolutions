#include <bits/stdc++.h>
using namespace std;

// 即 只能包含一个0 两个0就要收缩左指针了
int longestSubarray(vector<int>& nums) {
     int left = 0, ans = 0, cntZero = 0, tmp = 0;
     for (int right = 0; right < nums.size(); ++right) {
        // 进入
        if (nums[right] == 0) cntZero++; else tmp++;
        while (cntZero > 1) {
            // 左边收缩
            if (nums[left] == 0) cntZero--; else tmp--;
            left++;
        }
        ans = max(ans, tmp);
     }
     if (ans == nums.size()) return ans - 1;
     return ans;
}

int main() {
    vector<int> nums = {1,1,0,1};
    cout << longestSubarray(nums);
    return 0;
}