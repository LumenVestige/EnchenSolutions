#include <bits/stdc++.h>
using namespace std;

class MapSum {
    struct Node {
        Node* children[26];
        bool end = false;
        int val = 0;
    };
    Node* root = new Node();
    unordered_map<string, int> cnt;
public:
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        Node* p = root;
        int last = cnt[key];
        for (auto& c : key) {
            int idx = c - 'a';
            if (!p->children[idx]) {
                p->children[idx] = new Node();
            }
            p = p->children[idx];
            p->val -= last;
            p->val += val;
        }
        cnt[key] = val;
        p->end = true;
    }
    
    int sum(string prefix) {
        Node* p = root;
        for (auto& c : prefix) {
            int idx = c - 'a';
            if (!p->children[idx]) {
                return 0;
            }
            p = p->children[idx];
        }
        return p->val;
    }
};