//
// Created by sanenchen on 25-8-17.
//
#include <bits/stdc++.h>
using namespace std;

vector<int> corpFlightBookings(vector<vector<int> > &bookings, int n) {
    vector<int> diff(n + 2, 0);
    for (auto& it : bookings) {
        diff[it[0]] += it[2];
        diff[it[1] + 1] -= it[2];
    }
    // 将数据还原出来
    vector<int> books(n, 0);
    books[0] = diff[1];
    for (int i = 1; i < n; ++i) {
        books[i] = books[i - 1] + diff[i + 1];
    }
    return books;
}

int main() {
    vector<vector<int> > nums = {
        {1, 2, 10}, {2, 3, 20}, {2, 5, 25}
    };
    for (auto &it: corpFlightBookings(nums, 5)) {
        cout << it << " ";
    }
    return 0;
}
