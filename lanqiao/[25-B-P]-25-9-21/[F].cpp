#include <bits/stdc++.h>
using namespace std;

int main() {
    string str1, str2;
    cin >> str1 >> str2;
    int cnt1 = 0, cnt2 = 0;
    int left = str1.size(), right = -1;
    for (int i = 0; i < str1.size(); ++i) {
        if (str1[i] == '#' || str2[i] == '#') {
            left = min(left, i);
            right = max(right, i);
        }
        if (str1[i] == '#') cnt1++;
        if (str2[i] == '#') cnt2++;
    }
    int ans = min(right - left + 1 - cnt1, right - left + 1 - cnt2);
    cout << ans;
    return 0;
}