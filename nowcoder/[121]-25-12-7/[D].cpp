#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

signed main() {
    int n, k;
    cin >> n >> k;
    string str;
    cin >> str;
    vector<int> cnt(n + 1, 0);
    int c = 0, p = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '0') c++;
        else c = 0;
        if (c == k) {
            p++;
            c = 0;
        }
        cnt[i + 1] = p;
    }
    vector<int> ans(n + 1, 0);
    p = 0;
    for (int i = 0; i <= n; ++i) {
        while (p < n && cnt[p + 1] <= i) p++;
        ans[i] = p;
    }
    for (auto& i : ans) {
        cout << i << " ";
    }
    return 0;
}