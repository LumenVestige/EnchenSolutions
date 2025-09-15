#include<bits/stdc++.h>
using namespace std;

int canBeTypedWords(string text, string brokenLetters) {
    unordered_map<char, bool> brokeKey;
    for (auto& i : brokenLetters) brokeKey[i] = true;
    int ans = 0, cntBroken = 0;;
    for (auto& i : text) {
        if (brokeKey[i]) cntBroken++;
        if (i == ' ') {
            // 重置
            if (cntBroken == 0) ans++;
            cntBroken = 0;
        }
    }
    if (cntBroken == 0) ans++; // 末尾单词
    return ans;
}

int main() {
    cout << canBeTypedWords("leet code", "l");
    return 0;
}