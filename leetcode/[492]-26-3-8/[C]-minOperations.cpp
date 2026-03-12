#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int minOperations(string s) {
    // 特判一下 2
    if (s.size() == 2) {
        return s[0] <= s[1] ? 0 : -1;
    } else if (s.size() == 1) {
        return 0;
    }
    // 判断是否已经有序
    int flag = 0;
    char minChar = s[0], maxChar = s[0];
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] < s[i-1]) { // 当前这个字母小于前面那个数
            flag++;
        }
        minChar = min(minChar, s[i]);
        maxChar = max(maxChar, s[i]);
    }
    if (flag == 0) {
        return 0;
    }
    s.substr(1, s.size()-2);
    if (minChar == s[0] || maxChar == s[s.size()-1]) {
        return 1;
    } else if (s.find(minChar) == string::npos && s.find(maxChar) == string::npos) {
        return 3;
    } else {
        return 2;
    }
}
signed main() {
    cout << minOperations("edc");
    return 0;
}