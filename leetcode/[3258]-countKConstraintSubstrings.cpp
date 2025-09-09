//
// Created by sanenchen on 25-9-9.
//
#include <bits/stdc++.h>
using namespace std;

int countKConstraintSubstrings(string s, int k) {
    int left = 0, cnt_0 = 0, cnt_1 = 0, ans = 0;
    for (int right = 0; right < s.size(); ++right) {
        if (s[right] == '0') cnt_0++;
        else cnt_1++;
        while (cnt_0 > k && cnt_1 > k) {
            if (s[left] == '0') cnt_0--;
            else cnt_1--;
            left++;
        }
        if (cnt_0 <= k || cnt_1 <= k) ans += right - left + 1;
    }
    return ans;
}

int main() {
    cout << countKConstraintSubstrings("10101", 1);
    return 0;
}
