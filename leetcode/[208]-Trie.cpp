#include <bits/stdc++.h>
using namespace std;

class Trie {
    int trie[10000][26];
    bool end[10000];
    int tot = 0;
public:
    Trie() {
        end[0] = false;
        memset(trie[0], 0, sizeof(trie[0]));
    }
    
    void insert(string word) {
        int p = 0;
        for (auto& c : word) {
            int idx = c - 'a';
            if (!trie[p][idx]) {
                // 创建新
                trie[p][idx] = ++tot;
                end[tot] = false;
                memset(trie[tot], 0, sizeof(trie[tot]));
            }
            p = trie[p][idx];
        }
        end[p] = true;
    }
    
    bool search(string word) {
        int p = 0;
        for (auto& c : word) {
            int idx = c - 'a';
            if (!trie[p][idx])
                return false;
            p = trie[p][idx];
        }
        return end[p];
    }
    
    bool startsWith(string prefix) {
        int p = 0;
        for (auto& c : prefix) {
            int idx = c - 'a';
            if (!trie[p][idx])
                return false;
            p = trie[p][idx];
        }
        return true;
    }
};