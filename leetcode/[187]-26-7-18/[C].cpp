#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int MOD = 1e9+7;
int minAdjacentSwaps(vector<int>& nums, int a, int b) {
    // 排序，二分查找找范围
    int n = nums.size();
    auto bak = nums;
    sort(bak.begin(), bak.end());
    int totA = lower_bound(bak.begin(), bak.end(), a) - bak.begin();
    int totB = bak.end() - lower_bound(bak.begin(), bak.end(), b);
    // 第一步，右边符合条件的全部塞到右边去，从右往左拉
    int rightIndex = n-1;
    int ans = 0;
    vector<bool> block(n, false);
    for (int i = n-1; i >= 0; --i) {
        if (nums[i] > b) {
            ans += rightIndex - i;
            rightIndex--;
            cout << "select" << nums[i] << " " << i << endl;
            block[i] = true;
        }
    }
    cout << ans << endl;
    int leftIndex = 0;
    int leftCnt = 0;
    for (int i = 0; i < n; ++i) {
        if (block[i]) {
            continue;
        }
        if (nums[i] < a) {
            ans += leftCnt - leftIndex;
            leftIndex++;
            cout << "select" << nums[i] << " " << i << endl;
        }
        leftCnt++;
    }
    cout << totA << " " << totB << endl;
    return ans;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int> nums = {9,7,5,3};
    cout << minAdjacentSwaps(nums, 4, 8);
    return 0;
}