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
    static double myPow(double x, int n);
    static int findLucky(vector<int>& arr);
    static int lengthOfLongestSubstring(string s);
    static vector<int> findSubstring(string s, vector<string>& words);
    static string concatHex36(int n);
    static int countDays(int days, vector<vector<int>>& meetings);
    static vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive);
    static int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers);
};


#endif //SOLUTIONS_H
