#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> nums, int p, int dir) {
    while (p < nums.size() && p >= 0) {
        if (nums[p] > 0) {
            dir = -dir;
            nums[p]--;
        }
        p += dir;
    }
    for (auto& i : nums) {
        if (i != 0) return false;
    }
    return true;
}

int countValidSelections(vector<int>& nums) {
    int ans = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] == 0) {
            ans += solve(nums, i, 1);
            ans += solve(nums, i, -1);
        }
    }
    return ans;
}
int main() {
    vector<int> nums = {1, 0, 2, 0, 0};
    cout << countValidSelections(nums);
    return 0;
}