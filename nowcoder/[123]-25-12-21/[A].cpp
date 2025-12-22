#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

signed main() {
    int a, b;
    char a1, b1;
    cin >> a >> a1;
    cin >> b >> b1;
    if (a == b) {
        if (a1 < b1) {
            cout << "Yes";
            return 0;
        } else {
            cout << "No";
            return 0;
        }
    }
    if (a > b) {
        cout << "Yes";
        return 0;
    } else {
        cout << "No";
    }
    return 0;
}