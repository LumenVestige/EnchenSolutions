#include <bits/stdc++.h>
using namespace std;

int longestOnes(vector<int>& nums, int k) {
    int left = 0, ans = 0, tmp = 0, cnt = 0;
    for (int right = 0; right < nums.size(); ++right) {
        tmp++;
        cnt += (nums[right] == 0) ? 1 : 0;
        if (cnt > k) {
            // out
            tmp--;
            cnt -= (nums[left] == 0) ? 1 : 0;
            left++;
        }
        ans = max(ans, tmp);
    }
    return ans;
}

int main() {
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    cout << longestOnes(nums, 2) << endl;
    return 0;
}