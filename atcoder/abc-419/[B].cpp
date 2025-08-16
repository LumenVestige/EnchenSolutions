//
// Created by sanenchen on 25-8-16.
//
#include <bits/stdc++.h>
using namespace std;


int main() {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);
    priority_queue<int, vector<int>, greater<int>> s;
    int n;
    cin >> n;
    while (n--) {
        int q;
        cin >> q;
        if (q == 1) {
            int t;
            cin >> t;
            s.push(t);
        } else {
            cout << s.top() << endl;
            s.pop();
        }
    }
    return 0;
}