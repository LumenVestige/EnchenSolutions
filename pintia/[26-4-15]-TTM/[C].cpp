#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n;
    cin >> n;
    cout << n << endl;
    if (n == 0) {
        cout << "xian ren" << endl;
    } else if (n > 0) {
        cout << "nong ren" << endl;
    } else {
        cout << "dan ren" << endl;
    }
    return 0;
}