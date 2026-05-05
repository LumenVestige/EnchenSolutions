#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    string str;
    cin >> str;
    int left = 0, right = str.size()-1;
    while (left < right) {
        if (str[left] == str[right]) {
            left++, right--;
            continue;
        }
        if (str[left] == 'n' && left + 1 < right && str[left+1] == 'n') {
            left += 2, right--;
            continue;
        } 
        if (str[right] == 'n' && right - 1 > left  && str[right-1] == 'n') {
            left++, right -= 2;
            continue;
        }
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    return;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}