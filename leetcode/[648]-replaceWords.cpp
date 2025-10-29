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
        }
        end[p] = true;
    }
    string queryPrefix(string str) {
        bool searched = false;
        int p = 0;
        string prefix;
        for (auto& c : str) {
            if (searched) break;
            int idx = c - 'a';
            if (!trie[p][idx]) {
                return str;
            }
            p = trie[p][idx];
            prefix += c;
            searched = end[p];
        }
        return prefix;
    }
};

string replaceWords(vector<string>& dictionary, string sentence) {
    TrieTree trie;
    for (auto& i : dictionary) {
        trie.insert(i);
    }
    string tmp;
    string ans;
    sentence += " ";
    for (auto& c : sentence) {
        if (c == ' ') {
            ans += trie.queryPrefix(tmp) + " ";
            tmp = "";
            continue;
        }
        tmp += c;
    }
    return ans.substr(0, ans.size() - 1);
}

int main() {
    vector<string> dict = {"cat","bat","rat"};
    cout << replaceWords(dict, "the cattle was rattled by the battery");
    return 0;
}