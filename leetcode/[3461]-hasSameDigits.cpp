#include <bits/stdc++.h>
using namespace std;

bool hasSameDigits(string s) {
    while (s.size() != 2) {
        string tmp = "";
        for (int i = 1; i < s.size(); ++i) {
            int tar = (s[i - 1] - '0' + s[i] - '0') % 10;
            tmp += tar + '0';
        }
        s = tmp;
    }
    if (s[0] == s[1])
        return true;
    return false;
}

int main() {
    cout << hasSameDigits("323");
    return 0;
}