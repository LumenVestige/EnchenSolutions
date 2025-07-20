//
// Created by sanenchen on 25-7-3.
//

#ifndef SOLUTIONS_H
#define SOLUTIONS_H
#include <stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


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
    static string processStr(string s);
    static char processStr(string s, long long k);
    static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
    static long long splitArray(vector<int>& nums);
    static int countIslands(vector<vector<int>>& grid, int k);
};


#endif //SOLUTIONS_H
