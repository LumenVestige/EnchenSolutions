//
// Created by sanenchen on 25-7-3.
//

#ifndef SOLUTIONS_H
#define SOLUTIONS_H
#include <bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {
    }

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {
    }
};



class LeetCodes {
public:
    // 入口程序
    static void run();



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
    static vector<int> shuffle(vector<int>& nums, int n);
    static bool checkDivisibility(int n);
    static int countTrapezoids(vector<vector<int>> &points);
    static int numIslands(vector<vector<char>>& grid);
    static int maxVowels(string s, int k);
    static int maximumGain(string s, int x, int y);
    static int lengthOfLIS(vector<int>& nums);
    static long long maximumMedianSum(vector<int> &nums);
};


#endif //SOLUTIONS_H
