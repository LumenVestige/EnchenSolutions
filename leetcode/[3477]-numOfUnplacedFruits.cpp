//
// Created by sanenchen on 25-8-5.
//
#include <bits/stdc++.h>
using namespace std;

int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
    int cnt = 0;
    for (auto& f : fruits) {
        // 二分查找
        // int left = -1, right = baskets.size();
        // while (left + 1 < right) {
        //     int mid = (left + right) / 2;
        //     if (baskets[mid] >= f)
        //         right = mid;
        //     else left = mid;
        // }
        // if (right == baskets.size())
        //     ans++;
        // else baskets[right] = 0;
        for (int & basket : baskets) {
            if (basket >= f) {
                cnt++;
                basket = 0;
                break;
            }
        }
    }
    return fruits.size() - cnt;
}

int main() {
    vector<int> fruits = {5, 10, 2};
    vector<int> baskets = {8, 3, 10};
    cout << numOfUnplacedFruits(fruits, baskets);
    return 0;
    
}