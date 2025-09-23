#include <bits/stdc++.h>
using namespace std;

int compareVersion(string version1, string version2) {
    vector<int> log1, log2;
    // 分割
    string tmp;
    for (int i = 0; i < version1.size(); ++i) {
        if (version1[i] == '.') {log1.push_back(stoi(tmp));tmp = "";}
        else tmp += version1[i];
    }
    log1.push_back(stoi(tmp));
    tmp = "";
    for (int i = 0; i < version2.size(); ++i) {
        if (version2[i] == '.') {log2.push_back(stoi(tmp));tmp = "";}
        else tmp += version2[i];
    }
    log2.push_back(stoi(tmp));
    for (int i = 0; i < max(log1.size(), log2.size()); ++i) {
        int t1 = 0, t2 = 0;
        if (i < log1.size()) t1 = log1[i];
        if (i < log2.size()) t2 = log2[i];
        if (t1 > t2) return 1;
        if (t1 < t2) return -1;
    }
    return 0;
}

int main() {
    cout << compareVersion("1.2", "1.10");
    return 0;
}