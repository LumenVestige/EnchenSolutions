#include <bits/stdc++.h>
using namespace std;
int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
    vector<int> preR(rowCosts.size()+1), preC(colCosts.size()+1);
    for (int i = 1; i <= preR.size(); ++i) {
        preR[i] = preR[i-1] + rowCosts[i-1];
    }
    for (int i = 1; i <= preC.size(); ++i) {
        preC[i] = preC[i-1] + colCosts[i-1];
    }
    int ans = 0;
    if (startPos[1] < homePos[1]) {
        ans += preC[homePos[1]+1] - preC[startPos[1]+1];
    } else {
        ans += preC[startPos[1]+1] - preC[homePos[1]+1];
    }
    if (startPos[0] < homePos[0]) {
        ans += preR[homePos[0]+1] - preR[startPos[0]+1];
    } else {
        ans += preR[startPos[0]+1] - preR[homePos[0]+1];
    }
    return ans;
}
int main() {
    vector<int> startPos = {1, 0};
    vector<int> homePos = {2, 3};
    vector<int> row = {5, 4, 3};
    vector<int> col = {8, 2, 6, 7};
    cout << minCost(startPos, homePos, row, col);
}