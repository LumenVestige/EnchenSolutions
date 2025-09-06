#include<bits/stdc++.h>
using namespace std;

int maximumUniqueSubarray(vector<int>& nums) {
    unordered_map<int, int> cnt;
    int ans = 0, left = 0, tmp = 0;
    for (int right = 0; right < nums.size(); ++right) {
        // in
        tmp += nums[right];
        cnt[nums[right]]++;
        while (cnt[nums[right]] > 1) {
            tmp -= nums[left];
            cnt[nums[left]]--;
            left++;
        }
        ans = max(ans, tmp);
    }
    return ans;
}

int main() {
    vector<int> nums = {4,2,4,5,6};
    cout << maximumUniqueSubarray(nums) << endl;
    return 0;
}