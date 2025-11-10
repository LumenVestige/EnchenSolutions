#include <bits/stdc++.h>
using namespace std;

int minimumDistance(vector<int>& nums) {
    unordered_map<int, vector<int>> cnt;
    for (int i = 0; i < nums.size(); ++i) {
        cnt[nums[i]].push_back(i);
    }
    int ans = INT_MAX;
    for (auto& [k, vec] : cnt) {
        sort(vec.begin(), vec.end());
        // 定长滑动窗口
        int left = 0, right = 0;
        while (right < vec.size()) {
            if (right - left + 1 < 3) {
                right++;
                continue;
            }
            ans = min(ans, (abs(vec[left] - vec[right]) + abs(vec[left] - vec[left + 1]) + abs(vec[right] - vec[left + 1])));
            right++;
            left++;
        }
    }
    return ans == INT_MAX ? -1 : ans;
}

int main() {
    vector<int> nums = {1,2,1,1, 3};
    cout << minimumDistance(nums);
    return 0;
}