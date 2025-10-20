//
// Created by sanenchen on 25-10-20.
//
#include <bits/stdc++.h>
using namespace std;

bool check(string str) {
    int left = 0;
    unordered_map<char, int> cnt;
    for (int i = 0; i < str.size(); ++i) {
        cnt[str[i]]++;
        if (i - left + 1 < 3) {
            continue;
        }
        if (cnt['1'] == 1 && cnt['2'] == 1 && cnt['3'] == 1) {
            return true;
        }
        cnt[str[left]]--;
        left++;
    }
    return false;
}

void solve() {
    int n;
    string str;
    cin >> n >> str;

    if (check(str)) {
        cout << 0 << endl;
        return;
    }

    unordered_map<char, int> cnt;
    for (auto& i : str) {
        cnt[i]++;
    }
    if (cnt.size() != 3) {
        cout << -1 << endl;
        return;
    }
    cout << 1<< endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}