#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    string str;
    cin >> str;
    for (auto& i : str) {
        if (i != 'r' && i != 'e' && i != 'd') {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";

    return 0;
}