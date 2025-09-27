#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) 
        cin >> nums[i];
    nums.insert(nums.end(), nums.begin(), nums.end());
    nums.insert(nums.end(), nums.begin(), nums.end());
    vector<int> prefix(2 * n + 1, 0);
    for (int i = 1; i <= 2 * n; ++i) {
        prefix[i] = prefix[i - 1] + nums[i - 1];
    }
    int head = 0;
    while (q--) {
        int m;
        cin >> m;
        if (m == 1) {
            int times;
            cin >> times;
            head += times % n;
            // 要确保 head在 [0..n]中
            head = head % n;
        } else {
            int l, r;
            cin >> l >> r;
            cout << prefix[head + r] - prefix[head + l - 1] << endl;
        }
    }
    return 0;
}