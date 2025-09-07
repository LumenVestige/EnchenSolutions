//
// Created by sanenchen on 25-7-20.
//
#include "../LeetCodes.h"

int LeetCodes::countTrapezoids(vector<vector<int>>& points) {
    int ans = 0;
    int len = points.size();
    for (int i = 0; i < len - 3; ++i) {
        for (int j = i; j < len - 2; ++j) {
            for (int k = j; k < len - 1; ++ k) {
                for (int m = k; m < len; ++m) {
                    vector<int> p1 = points[i], p2 = points[j], p3 = points[k], p4 = points[m];
                }
            }
        }
    }

    return ans;
}