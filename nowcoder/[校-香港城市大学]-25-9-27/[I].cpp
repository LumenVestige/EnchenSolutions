#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int n;
    cin >> n;
    int l = 0, m = 0;
    while (n--) {
        int t;
        cin >> t;
        if (t > 0) l++;
        else m++;
        // 审查
        if (l > 0 && m > 0) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
    return 0;
}