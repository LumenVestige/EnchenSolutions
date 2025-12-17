#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int countPermutations(vector<int>& complexity) {
    unordered_map<int, int> cnt;
    int mi = INT_MAX;
    for (auto& i : complexity) {
        cnt[i]++;
        mi = min(mi, i);
    }
    int n = complexity.size();
    if (cnt[complexity[0]] > 1 || mi != complexity[0]) {
        return 0;
    }
    ll ans = 1;
    for (int i = 1; i < n; ++i) {
        ans *= i;
        ans %= (ll)(1e9 + 7);
    }
    return (int)(ans % (ll)(1e9 + 7));
}
int main() {
    vector<int> complexity = {3,3,3,4,4,4};
    cout << countPermutations(complexity);
    return 0;
}