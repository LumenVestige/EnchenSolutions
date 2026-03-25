#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define N 999999999
void solve(int n) {
    queue<int> canFroze;
    vector<int> ans(n);
    for (int i = 1; i <= n; ++i) {
        ans[i - 1] = i;
        if (gcd(i, N) != 1) {
            canFroze.push(i);
        }
    }
    int need = ceil(1.0 * n / 3);
    int t = 1;
    if (canFroze.size() >= need) {
        int pos = 1;
        while (!canFroze.empty()) {
            //cout << ans.size();
            while (pos < ans.size()) {
                swap(ans[pos], ans[canFroze.front() - 1]);
                canFroze.pop();
                pos += 3;
            }

        }
        pos = ++t;

    } else cout << "Baka!";
    for (auto& i : ans) {
        cout << i << " ";
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // int n;
    // cin >> n;
    // for (int i = 1; i < 80; ++i) {
    //     solve(i);
    //     cout << endl;
    // }
    solve(90);
    return 0;
}