#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string str;
    cin >> str;
    string t = str;
    reverse(str.begin(), str.end());
    if (t > str) {
        cout << "left";
    } else if (t < str) {
        cout << "right";
    } else {
        cout << "equal";
    }
    return 0;
}