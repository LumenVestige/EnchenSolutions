//
// Created by sanenchen on 25-7-3.
//

#include "LeetCodes.h"

using namespace std;
// 入口程序
void LeetCodes::run() {
    // T1 两数之和
    // vector<int> v = {2,7,11,15};
    // constexpr int target = 9;
    // for (auto &item: twoSum(v, target)) {
    //     cout << item << " ";
    // }

    // 456周赛 T1
    for (auto &item: partitionString("xm")) {
        cout << item << " ";
    }

    // T3304 找出第 K 个字符 I
    // cout << kthCharacterI(500) << endl;

    // T3307 找出第 K 个字符 II
    // vector<int> operations = {0,1,0,1,1,0,1,0,1,1,0,0,0,0,0,1,0,1,1,0,1,1,0,0,1};
    // cout << kthCharacterII(23980478, operations) << endl;
}


