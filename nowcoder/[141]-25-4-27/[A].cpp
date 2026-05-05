#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
bool isHui(int x) {
    string str = to_string(x);
    for (int i = 0; i < str.size() / 2; ++i) {
        if (str[i] != str[str.size()-i-1]) {
            return false;
        }
    }
    return true;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int sq = sqrt(n);
    if (sq*sq != n) {
        cout << "NO";
        return 0;
    }
    cout <<( isHui(n) && isHui(sqrt(n)) ? "YES" : "NO");
    return 0;
}