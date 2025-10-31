//
// Created by sanenchen on 25-10-31.
//
#include <bits/stdc++.h>
using namespace std;

class TrieTree {
    struct Node {
        Node* children[27];
        bool end = false;
    };
    Node* root = new Node();
public:
    bool insert(string& str) {
        Node* p = root;
        if (!query(str))
            return false;
        for (auto& i : str) {
            int idx;
            if (i == '/')
                idx = 26;
            else idx = i - 'a';
            if (!p->children[idx]) {
                p->children[idx] = new Node();
            }
            p = p->children[idx];
        }
        p->end = true;
        return true;
    }
    bool queryPrefix(string str) {
        Node* p = root;
        for (auto& i : str) {
            int idx;
            if (i == '/')
                idx = 26;
            else idx = i - 'a';
            if (!p->children[idx]) {
                return false;
            }
            p = p->children[idx];
        }
        //p->end = true;
        return p->end;
    }
    bool query(string& str) {
        string tmp;
        for (int i = 0 ; i < str.size(); ++i) {
            if (str[i] == '/' && i != 0) {
                if (queryPrefix(str.substr(0, i)))
                    return false;
            }
        }
        return true; // 真就是可以
    }
};

vector<string> removeSubfolders(vector<string>& folder) {
    sort(folder.begin(), folder.end());
    TrieTree trie;
    vector<string> ans;
    for (auto& i : folder) {
        if (trie.insert(i))
            ans.push_back(i);
    }
    return ans;
}

int main() {
    vector<string> folder = {"/ah/al/am","/ah/al"};
    for (auto& i : removeSubfolders(folder)) {
        cout << i << " ";
    }
    return 0;
}