#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
bool isYuan(char c) {
    return c == 'a' ||c == 'e' ||c == 'i' ||c == 'o' ||c == 'u';
}
void solve() {
    string str;
    cin >> str;
    str = " " + str;
    if (str.size() != 9) {
        cout << "Well-Being" << endl;
        return;
    }
    bool flag = true;
    for (int i = 1; i <= 8; ++i) {
        if (i % 2 == 0) {
            if (!isYuan(str[i])) flag = false;
        } else {
            if (isYuan(str[i])) flag = false;
        }
    }
    if (flag) {
        cout << "Suspected Virus" << endl;
    } else {
        cout << "Well-Being" << endl;
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}