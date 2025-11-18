#include <bits/stdc++.h>
using namespace std;

int minOperations(vector<int>& nums) {
    int n = nums.size(), gcd_all = 0, cnt1 = 0;
    for (int x : nums) {
        gcd_all = gcd(gcd_all, x);
        cnt1 += x == 1;
    }
    if (gcd_all > 1) return -1;
    if (cnt1) return n - cnt1;
    if (cnt1 > 0) return nums.size() - cnt1;
    // 尝试找到一个gcd为1的数字
    int minSize = INT_MAX;
    for (int i = 0; i < nums.size(); ++i) {
        int g = 0;
        for (int j = i; j < nums.size(); ++j) {
            g = gcd(g, nums[j]);
            if (g == 1) {
                minSize = min(minSize, j - i + 1);
            }
        }
    }
    return nums.size() + minSize - 2;
}

int main() {
    vector<int> nums = {2,6,3,4};
    cout << minOperations(nums);
    return 0;
}