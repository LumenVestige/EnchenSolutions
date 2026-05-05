#include <bits/stdc++.h>
using namespace std;
#define int long long
bool isYuan(char i) {
    if (i == 'i' || i == 'e' || i == 'a' || i=='o' || i=='u') {
        return true;
    } 
    return false;
}
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string str; cin >> str;
    int cnt = 0;
    unordered_set<char> se;
    unordered_set<int> pos;
    for (int j = 0; j < str.size(); ++j) {
        char i = str[j];
        if (isYuan(i)) {
            cnt = 0;
            se.clear();
        } else {
            se.insert(i);
            cnt++;
            if (cnt == 3 && se.size() != 1) {
                pos.insert(j);
                cnt = 1;
                se.clear();
                se.insert(i);
            } else if (cnt == 3 && se.size() == 1) {
                cnt = 2;
            }
        }
    }
    for (int i = 0; i < str.size(); ++i) {
        if (pos.count(i)) {
            cout << " ";
        }
        cout << str[i];
    }
    return 0;
}