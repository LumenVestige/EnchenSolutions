#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int minimumIndex(vector<int>& capacity, int itemSize) {
    int ans = -1, lastBox = INT_MAX;
    for (int i = 0; i < capacity.size(); ++i) {
        if (capacity[i] >= itemSize && capacity[i] < lastBox) {
            ans = i;
            lastBox = capacity[i];
        }
    }
    return ans;
}

signed main() {
    vector<int> cap = {1,5,3,7};
    cout << minimumIndex(cap, 3);
    return 0;
}