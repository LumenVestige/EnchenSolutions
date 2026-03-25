#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve(int n, int k) {
    // int n, k;
    // cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        nums[i] = i + 1;
    }
    // 构建不动点
    if (k + 1 == n) {
        cout << -1;
        return;
    }
    // reverse(nums.begin() + k, nums.end());
    if (n != k) {
        int tmp = nums[k];
        for (int i = k ; i < n - 1; i ++) {
            nums[i] = nums[i + 1];
        }
        nums[n - 1] = tmp;
    }
    for (auto& i : nums) {
        cout << i << " ";
    }
    
    // 校验
    int test = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] == i + 1) {
            test++;
        }
    }
    if (test == k) {
        cout << "测试通过";
    } else {
        cout << "ERRORRR";
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    for (int i = 1; i <= 10; ++i) {
        for (int j = 0; j <= i; ++j) {
            cout << "cph:" << i << " " << j << endl;
            solve(i, j);
            cout << endl;
        }
    }
    return 0;
}