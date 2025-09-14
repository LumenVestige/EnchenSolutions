#include<bits/stdc++.h>
#include<cctype>
#include<algorithm>
using namespace std;

vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
    unordered_map<string, string> origin, caseProm, vowelProm;
    // unordered_map<string, vector<int> > caseProm;
    for (auto& s : wordlist) {
        // 当前的放在origin中
        origin[s] = s;
        string lower = s;
        transform(s.begin(), s.end(), lower.begin(), ::tolower);
        if (caseProm.find(lower) == caseProm.end()) caseProm[lower] = s;
        // 将 lower 的元音替换为 ?
        for (auto& x : lower) {
            if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') x = '?';
        }
        if (vowelProm.find(lower) == vowelProm.end()) vowelProm[lower] = s;

    }
    vector<string> ans;
    for (auto& s : queries) {
        string lower = s;
        transform(s.begin(), s.end(), lower.begin(), ::tolower);
        string switchS = lower;
        for (auto& x : switchS) {
            if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') x = '?';
        }
        if (origin.find(s) != origin.end()) ans.push_back(origin[s]);
        else if (caseProm.find(lower) != caseProm.end()) ans.push_back(caseProm[lower]);
        else if (vowelProm.find(switchS) != vowelProm.end()) ans.push_back(vowelProm[switchS]);
        else ans.push_back("");
    }
    return ans;
}

int main() {
    vector<string> wordList = {"ae","aa"};
    vector<string> queries = {"UU"};
    for(auto& i: spellchecker(wordList, queries)) 
        cout << i << " ";
    return 0;
}