#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    string str;
    cin >> str;
    int tot = x+y;
    int T = tot/n, rem = tot%n;
    int cnt1 = 0;
    vector<int> p(n, T);
    for (int i = 1; i <= rem; ++i) {
        p[i-1]++;
    }
    int vx = x, vy = y;
    for (int i = 0; i < n; ++i) {
        if (p[i] == 0 && str[i] == '2') {
            str[i] = '0';
        }
        if (str[i] == '0') {
            vx -= p[i];
        } else if (str[i] == '1') {
            vy -= p[i];
        } else if (p[i] == T+1) {
            cnt1++;
        }
    }
    int vxNeedT1 = vx / (T + 1);
    int rem_w = vx % (T + 1);
    int vxNeedT = 0;
    
    if (rem_w > 0) {
        if (T != 0) {
            int k = (T - (rem_w % T)) % T;
            vxNeedT1 -= k;
        }
    } // 退位
    if (T != 0 && vxNeedT1 > cnt1) {
        int diff = vxNeedT1 - cnt1;
        int steps = (diff + T - 1) / T;
        vxNeedT1 -= steps * T;
    } // 限制到cnt1
    if (T != 0 && vxNeedT1 >= 0) {
        vxNeedT = (vx - (T + 1) * vxNeedT1) / T;
    } // vxNeedT 的计算
    // 优先 vx
    for (int i = 0; i < n; ++i) {
        if (vx <= 0) {
            break;
        }
        // if (str[i] == '2' && p[i] <= vx) {
        //     vx -= p[i];
        //     str[i] = '0';
        // }
        if (str[i] == '2' && p[i] == T && vxNeedT > 0) {
            vx -= p[i];
            str[i] = '0';
            vxNeedT--;
        } else if (str[i] == '2' && p[i] == T+1 && vxNeedT1 > 0) {
            vx -= p[i];
            str[i] = '0';
            vxNeedT1--;
        }
    }
    if (vx != 0) {
        cout << "-1" << endl;
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (str[i] == '2') {
            vy -= p[i];
            str[i] = '1';
        }
    }
    if (vy != 0) {
        cout << "-1" << endl;
        return;
    }
    cout << str << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}