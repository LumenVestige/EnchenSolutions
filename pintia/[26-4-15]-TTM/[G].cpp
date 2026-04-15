#include <bits/stdc++.h>
using namespace std;
#define int long long
struct Node {
    string submitTime;
    int No, Score;
};
signed main() {
    int n, m;
    cin >> n >> m;
    vector<Node> nodes(n);
    for (int i = 0; i < n; ++i) {
        string a, b;
        int c, d;
        cin >> a >> b >> c >> d;
        Node nd = Node{a+" "+b, c, d};
        nodes[i] = nd;
    }
    //cout << "OOO" << endl;
    unordered_map<int, pair<int, string>> umap; // 题号，得分，时间
    for (int i = 0; i < n; ++i) {
        auto node = nodes[i];
        if (!umap.count(node.No)) {
            umap[node.No] = {node.Score, node.submitTime};
        } else if (node.Score > umap[node.No].first) {
            umap[node.No] = {node.Score, node.submitTime};
        }
    }
    for (int i = 0; i < n; ++i) {
        auto node = nodes[i];
        if (umap[node.No].second == node.submitTime) {
            cout << node.submitTime << " " << node.No << " " << node.Score << endl;
        }
    }
    return 0;
}