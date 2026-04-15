#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int n;
    cin >> n;
    unordered_map<string, string> umap;
    while (n--) {
        string no, c;
        cin >> no >> c;
        umap[no] = c;
    } 
    cin >> n;
    vector<int> ans;
    for (int i = 1; i <= n; ++i) {
        int t;
        cin >> t;
        int cI = 0, cE = 0;
        while (t--) {
            string no;
            cin >> no;
            if (umap[no] == "i") {
                cI++;
            } else {
                cE++;
            }
        }
        if (cI == 0 || cE == 0) {
            ans.push_back(i);
        }
    }
    if (ans.size() == 0) {
        cout << "None";
    } else {
        for (int i = 0; i < ans.size()-1; ++i) {
            cout << ans[i] << " ";
        }
        cout << ans[ans.size()-1];
    }
    return 0;
}