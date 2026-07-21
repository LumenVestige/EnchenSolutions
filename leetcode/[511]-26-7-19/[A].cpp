#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
bool canReach(vector<int>& start, vector<int>& target) {
    return (start[0] + start[1]) % 2 == (target[0] + target[1]) % 2;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
    }
    return 0;
}