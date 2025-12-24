#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
#define int long long
void solve() {
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < 1LL << n; ++i) {
        nums.push_back(i);
    }
    string tmp = "";
    for (int i = 0; i < n; ++i) {
        tmp += '1';
    }
    while (tmp != "") {
        int react = 0;
        for (auto& i : tmp) {
            react = (react << 1) + i - '0';
        }
        cout << react << " ";
        tmp.erase(tmp.begin());
        nums.erase(find(nums.begin(), nums.end(), react));
    }
    for (auto& i : nums) {
        cout << i << " ";
    }
    cout << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}