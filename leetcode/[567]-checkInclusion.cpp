#include <bits/stdc++.h>
using namespace std;
bool checkInclusion(string s1, string s2) {
    int left = 0, right = 0, beZero = 0;
    unordered_map<char, int> cnt;
    unordered_map<char, int> back;
    for (auto& i : s1) {
        cnt[i]++;
    }
    back = cnt;
    int target = cnt.size();
    while (right < s2.size()) {
        if (!cnt.count(s2[right])) {
            right++;
            left = right;
            beZero = 0;
            cnt = back;
            continue;
        } else {
            cnt[s2[right]]--;
            if (cnt[s2[right]] == 0) beZero++;
        }
        right++;
        while (cnt[s2[right - 1]] < 0 && right > left) {
            if (cnt[s2[left]] == 0) {
                beZero--;
            }        
            cnt[s2[left]]++;
            left++;
        }
        if (beZero == target) {
            return true;
        }
    }
    return false;
}
int main() {
    cout << checkInclusion("qff", "ifisnoskikfqzrmzlv");
    return 0;
}