#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

struct TreeNode {
    int val;
    TreeNode* par;
    vector<TreeNode*> childrens;
    explicit TreeNode(const int x, TreeNode* p) : val(x){
        par = p;
    };
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int lower = 2 * m, upper = 1 + m * (1 + m) / 2;

    if (n < lower || n > upper) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;

    TreeNode* treeRoot = new TreeNode(1, nullptr);
    queue<TreeNode*> que;
    que.push(treeRoot);
    int leaNums = 0, index = 1;
    queue<TreeNode*> leaves;

    while (!que.empty()) {
        auto root = que.front();
        que.pop();
        if (leaNums < m) {
            TreeNode* left = new TreeNode(++index, root);
            root->childrens.push_back(left);
            if (leaNums < m - 1) {
                leaves.push(left);
            }
            leaNums++;
        }
        if (leaNums < m) {
            TreeNode* right = new TreeNode(++index, root);
            root->childrens.push_back(right);
            que.push(right);
        }
    }

    while (index < n) {
        auto top = leaves.front();
        leaves.pop();

        if (top->par->val == 1) {
            continue;
        }

        auto oldPar = top->par;
        auto grandPar = oldPar->par;

        TreeNode* newNode = new TreeNode(++index, grandPar);

        newNode->childrens.push_back(top);
        top->par = newNode;

        for (int j = 0; j < oldPar->childrens.size(); ++j) {
            if (oldPar->childrens[j]->val == top->val) {
                oldPar->childrens.erase(oldPar->childrens.begin() + j);
                break;
            }
        }

        grandPar->childrens.push_back(newNode);

        if (newNode->par->val != 1) {
            leaves.push(newNode);
        }
    }

    que.push(treeRoot);
    while (!que.empty()) {
        auto item = que.front();
        que.pop();
        for (int i = 0; i < item->childrens.size(); ++i) {
            cout << item->val << " " << item->childrens[i]->val << endl;
            que.push(item->childrens[i]);
        }
    }

    return 0;
}