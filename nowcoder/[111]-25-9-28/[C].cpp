#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> nums(n);
    for (int i = 0 ; i < n; ++i) {
        cin >> nums[i];
    }
    // 首先截取最后的不变量
    vector<int> cs(nums.begin() + x, nums.end());
    vector<int> does(nums.begin(), nums.begin() + x);
    int head = (head - k % x + x) % x;
    // cout << head << endl;
    // 先输出 head 到末尾
    // 在输出 头到head
    // 最后输出cs不变
    for (int i = head; i < does.size(); ++i) {
        cout << does[i] << " ";
    }
    for (int i = 0; i < head; ++i) {
        cout << does[i] << " ";
    }
    for (auto& i : cs) {
        cout << i << " ";
    }
    return 0;
}