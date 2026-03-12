#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
struct Trie {
    int nex[500010][26], cnt = 0;
    int end[500010];
    void insert(string s) {
        int p = 0;
        for (auto& c : s) {
            int idx = c - 'a';
            if (!nex[p][idx]) {
                nex[p][idx] = ++cnt;
            }
            p = nex[p][idx];
        }
        end[p] = 1;
    }
    int find(string s) {
        int p = 0;
        for (auto& c : s) {
            int idx = c - 'a';
            if (!nex[p][idx]) {
                return 0;
            }
            p = nex[p][idx];
        }
        if (end[p] == 1) {
            end[p]++;
            return 1;
        }
        return end[p];
    }
};
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Trie t;
    memset(t.end, 0, sizeof(t.end));
    memset(t.nex, 0, sizeof(t.end));
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        string str;
        cin >> str;
        t.insert(str);
    }
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string str; cin >> str;
        int r = t.find(str);
        if (r == 0) {
            cout << "WRONG" << endl;
        } else if (r == 1) {
            cout << "OK" << endl;
        } else {
            cout << "REPEAT" << endl;
        }
    }
    return 0;
}