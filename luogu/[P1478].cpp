#include<bits/stdc++.h>
using namespace std;
bool deCompare(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}
int main() {
    int n,s,a,b;
    vector<pair<int, int>> apples;
    cin >> n >> s >> a >> b;
    while (n--) {
        int x, y;
        cin >> x >> y;
        apples.push_back({x, y});
    }
    sort(apples.begin(), apples.end(), deCompare);
    int ans = 0;
    for (auto i : apples) {
        if (s >= i.second && i.first <= a + b) {
            s -= i.second;
            ans++;
        }
    }
    
    cout << ans;
    return 0;
}