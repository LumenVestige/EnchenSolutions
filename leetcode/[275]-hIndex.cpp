#include <bits/stdc++.h>
using namespace std;

int hIndex(vector<int>& citations) {
    // auto check = [&](int mid)->bool {
    //     int currentIndex = citations[mid];
    //     if (currentIndex >= mid && citations.size() - mid >= mid)
    //         return true;
    //     return false;
    // };
    // int left = -1, right = citations.size() + 1;
    // while (left + 1 < right) {
    //     int mid = left + (right - left) / 2;
    //     if (check(mid - 1)) left = mid;
    //     else right = mid;
    // }
    int n = citations.size();
    int left = 0, right = n + 1;
    while (left + 1 < right) {
        int mid = left + (right - left) / 2;
        if (citations[n - mid] >= mid) left = mid;
        else right = mid;
    }
    return left;
}

int main() {
    vector<int> citations = {0,1,3,5,6};
    cout << hIndex(citations) << endl;
    return 0;
}