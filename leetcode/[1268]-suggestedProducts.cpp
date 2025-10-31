#include <bits/stdc++.h>
using namespace std;
class TrieTree {
    
    struct Node {
        Node* children[26];
        bool end = false;
        priority_queue<string, vector<string>, greater<string>> pq;
    };
    Node* root = new Node();
public:
    TrieTree() {}
    void insert(string& str) {
        Node* p = root;
        int cnt = 0;
        for (auto& i : str) {
            int idx = i - 'a';
            if (!p->children[idx]) {
                p->children[idx] = new Node();
            }
            p = p->children[idx];
            p->pq.emplace(str);
        }
        p->end = true;
    }
    vector<string> query(string& str) {
        Node* p = root;
        vector<string> ans;
        int count = 0;
        string tmp;
        for (auto& i : str) {
            int idx = i - 'a';
            if (!p->children[idx]) {
                return {};
            }
            p = p->children[idx];
        }
        // 当前这个p已经干到最后一位了
        auto pq = p->pq;
        while (count < 3 && !pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
            count++;
        }
        return ans;
    }
};
vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
    TrieTree trie;
    for (auto& i : products) {
        trie.insert(i);
    }
    string tmp;
    vector<vector<string>> ans;
    for (auto& i : searchWord) {
        tmp += i;
        ans.push_back(trie.query(tmp));
    }
    return ans;
}

int main() {
    vector<string> products = {"mobile","mouse","moneypot","monitor","mousepad"};
    for (auto& i : suggestedProducts(products, "mouse")) {
        for (auto& j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
//sort(a.begin(),a.end(),greater<int>());
