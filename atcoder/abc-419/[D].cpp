//
// Created by sanenchen on 25-8-16.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    vector<int> diff(n + 2, 0);
    while (m--) {
        int l, r;
        cin >> l >> r;
        diff[l]++;       
        diff[r + 1]--;   
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        cnt += diff[i]; 
        if (cnt % 2 == 1) {
            cout << t[i - 1];  
        } else {
            cout << s[i - 1];  
        }
    }
    return 0;
}
