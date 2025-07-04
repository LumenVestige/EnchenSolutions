//
// Created by sanenchen on 25-7-3.
//

#ifndef SOLUTIONS_H
#define SOLUTIONS_H
#include <stdc++.h>
using namespace std;


class LeetCodes {
public:
    // 入口程序
    void run();
private:
    static vector<int> twoSum(vector<int> &nums, int target);
    static vector<string> partitionString(string s);
    static char kthCharacterI(int k);
    static char kthCharacterII(long long k, vector<int>& operations);
};


#endif //SOLUTIONS_H
