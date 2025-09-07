//
// Created by sanenchen on 25-7-23.
//
#include "LeetCodes.h"

int LeetCodes::maxVowels(string s, int k) {

    int left = 0, right = k - 1;
    int ans = 0;
    int fin_ans = 0;
    for (int i = left; i <= right; i++) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            ans++;
    }
    fin_ans = max(ans, fin_ans);
    while (right < s.length() - 1) {
        if (s[left] == 'a' || s[left] == 'e' || s[left] == 'i' || s[left] == 'o' || s[left] == 'u')
            ans--;
        if (s[right + 1] == 'a' || s[right + 1] == 'e' || s[right + 1] == 'i' || s[right + 1] == 'o' || s[right + 1] == 'u')
            ans++;
        fin_ans = max(ans, fin_ans);
        left++;right++;
    }

    return fin_ans;
}
