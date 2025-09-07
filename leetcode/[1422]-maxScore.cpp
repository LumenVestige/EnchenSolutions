//
// Created by sanenchen on 25-8-14.
//
#include <bits/stdc++.h>
using namespace std;

int counter(string str, char target) {
    int ans = 0;
    for (auto& it : str) {
        if (it == target)
            ans ++;
    }
    return ans;
}

int maxScore(string s) {
    int ans = 0;
    // 切割 p 代表的位置
    for (int p = 0; p < s.size() - 1; p++) {
        // 切割
        string left = s.substr(0, p + 1);
        string right = s.substr(p + 1);
        ans = max(ans, (counter(left, '0') + counter(right, '1')));
    }
    return ans;
}

int main() {
    cout << maxScore("011101");
    return 0;
}