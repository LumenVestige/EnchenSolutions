//
// Created by sanenchen on 25-7-3.
//

#ifndef SOLUTIONS_H
#define SOLUTIONS_H
#include <stdc++.h>
using namespace std;


class Solutions {
public:
    // 入口程序
    void run();
private:
    static vector<int> twoSum(vector<int> &nums, int target);
    static vector<string> partitionString(string s);
    static char kthCharacterI(int k);
};


#endif //SOLUTIONS_H
