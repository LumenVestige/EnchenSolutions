//
// Created by sanenchen on 25-9-27.
//
#include <bits/stdc++.h>
using namespace std;
string majorityFrequencyGroup(string s) {
    unordered_map<char, int> cnt_1;
    for (auto& i: s) {
        cnt_1[i]++;
    }
    // 遍历cnt_1
    unordered_map<int, vector<char>> cnt_2;
    for (auto& [a, b] : cnt_1) {
        cnt_2[b].push_back(a);
    }
    pair<int, vector<char>> better = {-1, {}};
    for (auto& [a, b] : cnt_2) {
        if (b.size() > better.second.size() || (b.size() == better.second.size() && a > better.first)) {
            better = {a, b};
        }
    }
    string ans;
    for (auto& i : better.second) {
        ans += i;
    }
    sort(ans.begin(), ans.end());
    return ans;
}
int main() {
    cout << majorityFrequencyGroup("esejytaspxcgxqzchgcoeerdimjpmhpnegqsyzdzdsifkbbypp");
    return 0;
}