#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    unordered_map<char, int> cnt;
    for (auto& i : s) {
        cnt[i]++;
    }
    // target
    string target = "Kato_Shoko";
    unordered_map<char, int> tarCnt;
    for (auto& i : target) {
        tarCnt[i]++;
    }
    // 判断是否满足最低条件
    for (auto [a,b] : tarCnt) {
        if (cnt[a] < b) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES " << n - 10;
    return 0;
}