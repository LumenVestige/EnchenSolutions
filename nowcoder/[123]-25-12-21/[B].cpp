#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

signed main() {
    vector<int> vecH(13), vecZ(13);
    for (int j = 0; j < 13; ++j) {
            cin >> vecH[j];
    }
    for (int j = 0; j < 13; ++j) {
            cin >> vecZ[j];
    }
    int ans = 0;
    for (int i = 0; i < 13; ++i) {
        ans += abs((vecH[i] + vecZ[i]) - 4);
    }
    cout << ans / 2;
    return 0;
}