#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
string rearrangeString(string s, char x, char y) {
    unordered_map<char, int> cnt;
    for (auto& i : s) {
        cnt[i]++;
    }
    string ans;
    for (int i = 0; i < cnt[y]; ++i) {
        ans += y;
    }
    for (char a = 'a'; a <= 'z'; ++a) {
        if (a != y) {
            for (int i = 0; i < cnt[a]; ++i) {
                ans += a;
            }
        }
    }
    return ans;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
    }
    return 0;
}