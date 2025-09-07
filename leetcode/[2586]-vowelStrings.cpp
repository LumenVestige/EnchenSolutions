//
// Created by sanenchen on 25-8-14.
//
#include <bits/stdc++.h>
using namespace std;
bool isVowel(string s) {
    return (s[0] == 'a' || s[0] == 'e' || s[0] == 'i' || s[0] == 'o' || s[0] == 'u') &&
        (s[s.size() - 1] == 'a' || s[s.size() - 1] == 'e' || s[s.size() - 1] == 'i' || s[s.size() - 1] == 'o' || s[s.size() - 1] == 'u');
}
int vowelStrings(vector<string>& words, int left, int right) {
    int ans = 0;
    for (int i = left; i <= right; ++i) {
        if (isVowel(words[i]))
            ans ++;
    }
    return ans;
}
int main() {
    vector<string> words = {"hey","aeo","mu","ooo","artro"};
    cout << vowelStrings(words, 1, 4);
    return 0;
}