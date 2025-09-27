#include <bits/stdc++.h>
using namespace std;
#define int long long
int solve() {
    int n;
    cin >> n;
    vector<string> days(3);
    for (int i = 0; i < 3; ++i) {
        string s;
        cin >> s;
        days[i] = s;
    }
    int ans = 0;
    bool beContinue = false;
    for (int i = 0; i < n; ++i) {
        int a = days[0][i] - '0', b = days[1][i] - '0', c = days[2][i] - '0';
        if (a + b + c < 2) {
            continue;
        } 
        if (a + b + c == 3) {
            ans++;
            beContinue = false;
            continue;
        }
        if (i > 0) {
            int pa = days[0][i - 1] - '0', pb = days[1][i - 1] - '0', pc = days[2][i - 1] - '0';
            if (pa == a && pb == b && pc == c) {
                if (beContinue) {
                    beContinue = false;
                    ans++;
                } else {
                    beContinue = true;
                }
                continue;
            } 
            ans++;
            beContinue = false;
        } else if (a + b + c >= 2) {
            beContinue = false;
            ans++;
        }

    }
    cout << ans << endl;
    return 0;
}
signed main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}