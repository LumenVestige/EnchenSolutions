//
// Created by sanenchen on 25-8-21.
//
#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    string s;
    cin >> n >> s;
    int m;
    cin >> m;
    string b, c;
    cin >> b >> c;
    deque<char> dq;
    for (int i = 0; i < n; ++i) {
        dq.push_back(s[i]);
    }
    for (int i = 0; i < m; ++i) {
        if (c[i] == 'V')
            dq.push_front(b[i]);
        else dq.push_back(b[i]);
    }
    for (auto& it : dq) {
        cout << it;
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}