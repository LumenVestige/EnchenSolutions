#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    string t = "";
    while (true) {
        string s;
        getline(cin, s);
        if (s == "#") {
            cout << t;
            return 0;
        }
        t += s + "\n";
    }
    return 0;
}