#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> nums(n + 2);
    int ans = 0;
    if (n == 1) {
        cout << 1;
    }
    for (int i = 1; i <= n; ++i) {
        int tmp;
        cin >> tmp;
        nums[tmp]++;
        if (tmp == 1) {
            if (nums[tmp] > nums[tmp + 1]) ans++;
        } else if (tmp == n) {
            if (nums[tmp] > nums[tmp - 1]) ans++;
        } else if (nums[tmp] > nums[tmp - 1] && nums[tmp] > nums[tmp + 1]) ans++;
        else if (nums[tmp] <= nums[tmp - 1] && nums[tmp] <= nums[tmp + 1]) ans--;
        cout << ans << " ";
    }
    return 0;
}