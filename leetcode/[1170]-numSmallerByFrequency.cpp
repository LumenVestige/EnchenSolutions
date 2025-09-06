//
// Created by sanenchen on 25-8-15.
//
#include <bits/stdc++.h>
using namespace std;

vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
    vector<int> ans;
    auto upperBound = [&](string str, char target) {
        int left = -1, right = str.size();
        while (left + 1 != right) {
            int mid = left + (right - left) /2;
            if (str[mid] <= target)
                left = mid;
            else right = mid;
        }
        return right;
    };
    for (auto& it : queries) {

        sort(it.begin(), it.end());
        int count1 = upperBound(it, it[0]);
        int counter = 0;
        for (auto& str2 : words) {
            sort(str2.begin(), str2.end());
            int count2 = upperBound(str2, str2[0]);
            // cout << count2 << " ";
            if (count2 > count1)
                counter++;
        }
        ans.push_back(counter);
    }
    return ans;
}

int main() {
    vector<string> queries = {"bbb","cc"};
    vector<string> word = {"a","aa","aaa","aaaa"};
    for (auto& it : numSmallerByFrequency(queries, word)) {
        cout << it << " ";
    }
    return 0;
}


