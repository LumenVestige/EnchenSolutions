//
// Created by sanenchen on 25-8-15.
//
#include <bits/stdc++.h>
#include <__memory/ranges_construct_at.h>
using namespace std;

class RangeFreqQuery {
private:
    int lowerBound(vector<int> &arr, int target) {
        int left = -1, right = arr.size();
        while (left + 1 != right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] >= target)
                right = mid;
            else left = mid;
        }
        return right;
    }

    int upperBound(vector<int> &arr, int target) {
        int left = -1, right = arr.size();
        while (left + 1 != right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] <= target)
                left = mid;
            else right = mid;
        }
        return right;
    }

public:
    // 哈希表来预处理
    unordered_map<int, vector<int> > hashmap;

    RangeFreqQuery(vector<int> &arr) {
        for (int i = 0; i < arr.size(); ++i) {
            hashmap[arr[i]].push_back(i);
        }
    }

    int query(int left, int right, int value) {
        auto it = hashmap.find(value);
        // 获取位置数组
        if (it == hashmap.end())
            return 0;
        int lower = lowerBound(hashmap.find(value)->second, left);
        int upper = upperBound(hashmap.find(value)->second, right);

        return upper - lower;
    }
};


int main() {
    vector<int> nums = {12, 33, 4, 56, 22, 2, 34, 33, 22, 12, 34, 56};
    RangeFreqQuery rangeFreqQuery(nums);
    cout << rangeFreqQuery.query(0, 11, 33);
    return 0;
}
