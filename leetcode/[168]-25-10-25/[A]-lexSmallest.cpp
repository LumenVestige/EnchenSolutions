//
// Created by sanenchen on 25-10-25.
//
#include <bits/stdc++.h>
using namespace std;
string lexSmallest(string s) {
    string m = s;
    // 正着扫
    for (int i = 0; i <= s.size(); ++i) {
        string t = s;
        reverse(t.begin(), t.begin() + i);
        m = min(m, t);
    }
    for (int i = 0; i <= s.size(); ++i) {
        string t = s;
        reverse(t.end() - i, t.end());
        m = min(m, t);
    }
    return m;
}
int main() {
    cout << lexSmallest("dcab");
    cout << (string("abcd") < "dcab");
    return 0;
}