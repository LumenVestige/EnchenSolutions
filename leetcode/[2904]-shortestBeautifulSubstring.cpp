#include<bits/stdc++.h>
using namespace std;
string shortestBeautifulSubstring(string s, int k) {
    int left = 0, cnt = 0;
    string ans = s;
    if (count(s.begin(),s.end(), '1') < k) return "";
    for (int right = 0; right < s.size(); ++right) {
        if (s[right] == '1') cnt++;
        // out
        while (cnt > k) {
            if (s[left] == '1') cnt--;
            left++;
        }
        while (cnt == k) {
            string t = s.substr(left, right - left + 1);
            if (t.size() < ans.size() || (t.size() == ans.size() && t < ans)) {
                ans = move(t);
            }
            if (s[left] == '1') cnt--;
            left++;
        }
    }
    return ans;
}
int main() {
    cout << shortestBeautifulSubstring("100011001", 3) << endl;
    return 0;
}