#include <bits/stdc++.h>
using namespace std;

int minLength(string s) {
    stack<int> ans;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'B' && !ans.empty()) {
            if (ans.top() == 'A') ans.pop();
            else ans.push(s[i]);
        } else if (s[i] == 'D' && !ans.empty()) {
            if (ans.top() == 'C') ans.pop();
            else ans.push(s[i]);
        } else ans.push(s[i]);
    }
    int c = 0;
    while (!ans.empty()) {
        c++;
        ans.pop();
    }
    return c;
}

int main() {
    cout << minLength("ABFCACDB");
    return 0;
}