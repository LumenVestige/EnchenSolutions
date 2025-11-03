//
// Created by sanenchen on 25-10-30.
//
#include <bits/stdc++.h>
using namespace std;

class TrieTree {
private:
    struct Node {
        Node* children[26] = {nullptr};
        int count = 0;
    };
    Node* root;
    // const static int tag = 500001;
    // int trie[tag][26]{};
    // bool end[tag]{};
    // int cnt[tag][26]{};
    // int tot = 0;
public:
    TrieTree() : root(new Node()) {}
    void insert(const string& str) {
        Node* p = root;
        for (auto& c : str) {
            int idx = c - 'a';
            if (!p->children[idx]) {
                p->children[idx] = new Node();
            }
            p = p->children[idx];
            p->count++;
        }
    }
    int queryPrefix(const string& str) {
        int ans = 0;
        Node* p = root;
        for (auto& c : str) {
            int idx = c - 'a';
            if (!p->children[idx]) {
                return ans;
            }
            p = p->children[idx];
            ans += p->count;
        }
        return ans;
    }
};

vector<int> sumPrefixScores(vector<string>& words) {
    // 建树
    TrieTree trie;
    for (auto& i : words) {
        trie.insert(i);
    }
    vector<int> ans;
    for (auto& i : words) {
        ans.push_back(trie.queryPrefix(i));
    }
    return ans;
}


int main() {
    vector<string> words = {"abc","ab","bc","b"};
    for (auto& i : sumPrefixScores(words)) {
        cout << i << " ";
    }
    return 0;
}