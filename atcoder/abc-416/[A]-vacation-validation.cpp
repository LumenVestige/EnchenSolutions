//
// Created by sanenchen on 25-7-26.
//
#include <bits/stdc++.h>

using namespace std;
int main() {
    int n, l, r;
    string s;
    cin >> n >> l >> r >> s;
    for (int i = l - 1; i < r; i++) {
        if (s[i] != 'o') {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
    // if (s[r - 1] == 'o' && s[l - 1] == 'o')
    //     cout << "Yes";
    // else
    //     cout << "No";
    return 0;
}