#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    char o[2] = {'o', 'O'}, v[2] = {'v', 'V'};
    string str; cin >> str;
    int cnt;
    cnt = 0;
    for (auto& i : o) {
        if (str[0] != i) {
            cnt++;
        }
        if (str[2] != i) {
            cnt++;
        }
    }
    for (auto& i : v) {
        if (str[1] != i) {
            cnt++;
        }
    }
    if (cnt > 3) {
        cout << "NO";
    } else {
        cout << "YES";
    }
    return 0;
}