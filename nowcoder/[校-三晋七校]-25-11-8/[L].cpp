#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    // 双指针
    int ans = 0;
    int left = 0, right = 0, tmp = 0;
    int cnt = 0;
    while (right < s.length()) {
        if (s[right] == '(') {
            left = right;
            cnt = 0;
        }
        if (s[right] == ')' && cnt == 0) {
            ans = max(ans, right - left + 1);
            cnt++;
        }
        right++;
    }
    cout << ans;
    return 0;
}