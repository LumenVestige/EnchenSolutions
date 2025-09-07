//
// Created by sanenchen on 25-7-5.
//
#include "LeetCodes.h"

int LeetCodes::findLucky(vector<int> &arr) {
    unordered_map<int, int> m;
    // set<int> temp_ans;

    for (auto it : arr) {
        m[it]++;
    }

    int temp_ans = -1;
    for (auto it : arr) {
        if (m[it] == it) {
            //temp_ans.insert(it);
            if (temp_ans < it)
                temp_ans = it;
        }
    }
    // if (!temp_ans.empty()) {
    //     return *temp_ans.rbegin();
    // }
    return temp_ans;
}