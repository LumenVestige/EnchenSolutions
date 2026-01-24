#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    string s;
    cin >> s;
    int cnt = 0;
    for (auto i : s) {
        cnt += i == 'i' || i == 'j' ? 1 : 0;
    }
    cout << cnt;
    return 0;
}