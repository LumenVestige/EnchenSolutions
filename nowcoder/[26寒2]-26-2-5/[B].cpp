#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    int n; cin >> n;
    vector<int> nums(n);
    int MAX = LLONG_MIN;
    unordered_map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        MAX = max(MAX, nums[i]);
        cnt[nums[i]]++;
    }
    int MAX_COUNT = cnt[MAX];
    string str;
    for (int i = 0; i < n; ++i) {
        bool f = cnt[MAX] % 2 == 0;
        if (nums[i] == MAX) {
            if (f) {
                str += '0';
            } else {
                str += '1';
            }
        } else {
            if (f) {
                str += '1';
            } else {
                str += '0';
            }
        }
    }
    cout << str << endl;

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}