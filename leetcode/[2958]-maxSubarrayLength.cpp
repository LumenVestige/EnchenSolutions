#include<bits/stdc++.h>
using namespace std;

int maxSubarrayLength(vector<int>& nums, int k) {
    int left = 0, ans = 0, tmp = 0;
    unordered_map<int, int> cnt;
    for (int right = 0; right < nums.size(); ++right) {
        // in
        tmp++;
        cnt[nums[right]]++;
        // check
        while (cnt[nums[right]] > k) {
            // out
            cnt[nums[left]]--;
            tmp--;
            left++;
        }
        ans = max(ans, tmp);
    }
    return ans;
}

int main() {
    vector<int> nums = {1,2,3,1,2,3,1,2};
    cout << maxSubarrayLength(nums, 2) << endl;
    return 0;
}