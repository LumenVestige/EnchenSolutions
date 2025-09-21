//
// Created by sanenchen on 25-9-21.
//
#include <bits/stdc++.h>
using namespace std;
int evenNumberBitwiseORs(vector<int>& nums) {
    vector<int> o;
    for (auto i : nums) {
        if (i % 2 == 0)
            o.push_back(i);
    }
    if (o.size() == 0) return 0;
    int ans = o[0];
    for (int i = 1; i < o.size(); ++i)
        ans &= o[i];
    return ans;
}
int main() {

}