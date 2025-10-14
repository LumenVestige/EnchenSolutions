#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    vector<vector<int>> ans;
    vector<int> tmp;
    function<void(int, vector<int>)> dfs = [&](int x, vector<int> con) {
        tmp.push_back(x);
        int size = graph.size();
        if (x == size - 1) {
            ans.push_back(tmp);
            tmp.pop_back();
            return ;
        }
        for (auto& i : con) {
            dfs(i, graph[i]);
        }
        tmp.pop_back();
    };
    dfs(0, graph[0]);
    return ans;
}
int main() {
    vector<vector<int>> graph = {{1,2},{3},{3},{}};
    for (auto& i : allPathsSourceTarget(graph)) {
        for (auto& j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}