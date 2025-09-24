#include <bits/stdc++.h>
using namespace std;
long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
    vector<int> nextCostPrefix(nextCost.size() + 1, 0), previousCostPrefix(previousCost.size() + 1, 0);
    for (int i = 1; i <= nextCost.size(); ++i) 
        nextCostPrefix[i] = nextCostPrefix[i - 1] + nextCost[i - 1];
    for (int i = 1; i <= previousCost.size(); ++i) 
        previousCostPrefix[i] = previousCostPrefix[i - 1] + previousCost[i - 1];
    long long ans = 0;
    for (int i = 0 ; i < s.size(); ++i) {
        // 计算二者差值
        // int diff = abs(s[0] - t[0]);
        // int pa = nextCostPrefix[26 - diff - 1];
        // int pb = previousCostPrefix[diff - 1];
        // ans += min(pa, pb);
        int pa = 0;
        // 向后处理
        if (s[i] < t[i]) {
            pa = nextCostPrefix[t[i] - 'a'] - nextCostPrefix[s[i] - 'a'];
        } else {
            pa = nextCostPrefix[nextCostPrefix.size() - 1] - (nextCostPrefix[t[i] - 'a'] - nextCostPrefix[s[i] - 'a']);
        }
        int pb = 0;
        if (s[i] < t[i]) {
            pb = previousCostPrefix[t[i] - 'a'] - previousCostPrefix[s[i] - 'a'];
        } else {
            pb = previousCostPrefix[previousCostPrefix.size() - 1] - (previousCostPrefix[t[i] - 'a'] - previousCostPrefix[s[i] - 'a']);
        }
        ans += min(pa, pb);
    }
    return ans;
}
int main() {
    vector<int> nextCost = {100,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    vector<int> previousCost = {1,100,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    cout << shiftDistance("abab", "baba", nextCost, previousCost);
    return 0;
}