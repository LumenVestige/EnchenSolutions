#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
struct Node{
    int score;
    int pos;
};
bool comp(const Node& a, const Node& b) {
    return a.score > b.score;
}
signed main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<Node> nums(n);
    int i_score; 
    for (int i = 0; i < n; ++i) {
        int c;
        cin >> c;
        nums[i] = {c, i};
        if (i == 8) i_score = c;
    }
    sort(nums.begin(), nums.end(), comp);
    int check = 0;
    for (auto& node : nums) {
        if (node.score > i_score) check++;
    }
    if (check <= 2 || (i_score * 10 >= m * 8)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}