#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string str;
    cin >> n >> str;
    int startPos = -1;
    bool lock = false;
    for (int i = 0; i < n; ++i) {
        if (!lock && str[i] != 'o') {
            startPos = i;
            lock = true;
            break;
        }
    }
    if (startPos == -1) {
        cout << "";
        return 0;
    }
    cout << str.substr(startPos, n-startPos);
    return 0;
}