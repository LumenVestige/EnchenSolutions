#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int cur = (n % 2 == 0) ? n : n-1;
    queue<int> que;
    que.push(2);
    cur += 2;
    while (!que.empty()) {
        int size = que.size();
        for (int i = 0; i < size; ++i) {
            int par = que.front();
            cout << par << " ";
            que.pop();
            cur -= 2;
            if (cur == 2 || cur == 0) {
                cur = (n % 2 == 0) ? n-1 : n;
            }
            if (cur > 0 && cur != 2) {
                que.push(cur);
            }
        }
    }
    return 0;
}