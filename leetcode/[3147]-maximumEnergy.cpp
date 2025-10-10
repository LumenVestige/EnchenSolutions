#include <bits/stdc++.h>
using namespace std;
int maximumEnergy(vector<int>& energy, int k) {
    int ans = INT_MIN;
    for (int i = 1; i <= k; ++i) {
        int tmp = 0;
        for (int j = energy.size() - i; j >= 0; j -= k) {
            tmp += energy[j];
            ans = max(ans, tmp);
        }
    }
    return ans;
}
int main() {
    vector<int> energy = {5,2,-10,-5,1};
    cout << maximumEnergy(energy, 3);
    return 0;
}