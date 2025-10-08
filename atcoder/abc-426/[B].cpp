//
// Created by sanenchen on 25-10-4.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<char, int> cnt;
    string s;
    cin >> s;
    for (auto& i : s) {
        cnt[i]++;
    }
    for (auto& [x, y] : cnt) {
        if (y == 1) {
            cout << x;
        }
    }
    return 0;
}