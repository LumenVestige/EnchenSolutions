#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    int n;
    cin >> n;
    vector<int> nums(n);

    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    
    int ans = 1;
    int maAns = 1;
    int tmp = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        if (tmp + 1 == nums[i]) {
            ans++;
            tmp = nums[i];
        } else {
            ans = 1;
            tmp = nums[i];
        }
        maAns = max(maAns, ans);
    }
    cout << maAns << endl;
}
signed main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}