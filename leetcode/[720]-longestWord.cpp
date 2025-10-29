#include <bits/stdc++.h>
using namespace std;
class TrieTree{
    int trie[10000][26];
    bool end[10000];
    int tot = 0;
public:
    TrieTree() {
        memset(trie[0], 0, sizeof(trie[0]));
        end[0] = false;
    }
    void insert(string str) {
        int p = 0;
        for (auto& c : str) {
            int idx = c - 'a';
            if (!trie[p][idx]) {
                trie[p][idx] = ++tot;
                memset(trie[tot], 0, sizeof(trie[tot]));
                end[tot] = false;
            }
            p = trie[p][idx];
            end[p] = false;
        }
        end[p] = true;
    }
    bool query(string str) {
        int p = 0;
        string prefix;
        for (auto& c : str) {
            int idx = c - 'a';
            if (!trie[p][idx]) {
                return false;
            }
            p = trie[p][idx];
            prefix += c;
        }
        return end[p];
    }
    bool queryPrefix(string str) {
        int p = 0;
        string prefix;
        for (auto& c : str) {
            int idx = c - 'a';
            if (!trie[p][idx]) {
                return false;
            }
            p = trie[p][idx];
            prefix += c;
        }
        return true;
    }
};

string longestWord(vector<string>& words) {
    TrieTree trie;
    sort(words.begin(), words.end());
    for (auto& s : words) {
        if (trie.queryPrefix(s.substr(0, s.size() - 1))) trie.insert(s);
    }
    set<string> res;
    int count = 0;
    for (auto& s : words) {
        if (s.size() >= count) {
            if (trie.query(s)) {
                if (s.size() > count) res.clear();
                count = s.size();
                res.insert(s);
            }
        }
        
    }
    if (res.empty()) return "";
    return *res.begin();
}

int main() {
    vector<string> words = {"a","banana","app","appl","ap","apply","apple"}; 
    cout << longestWord(words);
    return 0;
}