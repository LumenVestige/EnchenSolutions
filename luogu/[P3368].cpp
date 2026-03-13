#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int s[500005], n;
int lowBit(int x) {
    return x & -x;
}
void change(int x, int k) {
    while(x <= n) {
        s[x] += k;
        x += lowBit(x);
    }
}

int query(int x) {
    int t = 0;
    while (x) {
        t += s[x];
        x -= lowBit(x);
    }
    return t;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m;
    cin >> n >> m;
    vector<int> nums(n);
    for (int i = 1; i <= n; ++i) {
        cin >> nums[i];
    }
    while (m--) {
        int k;
        cin >> k;
        if (k == 1) {
            int x, y, v;
            cin >> x >> y >> v;
            change(x, v); change (y + 1, -v);
        } else {
            int x;
            cin >> x;
            cout << nums[x] + query(x) << endl;
        }

    }
    return 0;
}