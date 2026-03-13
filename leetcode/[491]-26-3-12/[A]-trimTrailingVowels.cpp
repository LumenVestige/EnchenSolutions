#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

string trimTrailingVowels(string s) {
    int z = s.size();
    char t[5] = {'a','e','i','o','u'};
    for (int i = s.size() - 1; i >= 0; i--) {
        int f = 0;
        for (auto c : t) {
            if (s[i] == c) {
                f++;
                break;
            }
        }
        if (f != 0) {
            z--;
        } else {
            break;
        }
    }
    s = s.substr(0, z);
    return s;
}

signed main() {
    cout << trimTrailingVowels("idea");
    return 0;
}