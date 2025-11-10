//
// Created by sanenchen on 25-11-9.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_map<int, set<int>> cnt;
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        cnt[l].insert(r);
        cnt[r].insert(l);
        if (cnt[l].size() == n - 1) {
            cout << l;
            return 0;
        }
    }
    return 0;
}