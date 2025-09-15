//
// Created by sanenchen on 25-9-15.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    // 全都塞进set中
    set<int> s;
    while (n--) {
        int t;
        cin >> t;
        s.insert(t);
    }
    cout << s.size() << endl;
    for (auto& i : s) {
        cout << i << " ";
    }
    return 0;
}