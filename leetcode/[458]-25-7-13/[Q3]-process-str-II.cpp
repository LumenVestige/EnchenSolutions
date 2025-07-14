//
// Created by sanenchen on 25-7-13.
//
#include "../LeetCodes.h"
char LeetCodes::processStr(string s, long long k) {
    vector<char> vec_str;
    // 遍历 s
    for (auto c : s) {
        switch (c) {
            case ('*'):
                if (!vec_str.empty())
                    vec_str.erase(vec_str.end() - 1);
                break;
            case ('#'):
                vec_str.insert(vec_str.end(), vec_str.begin(), vec_str.end());
                break;
            case ('%'):
                ranges::reverse(vec_str);
                break;
            default:
                vec_str.push_back(c);
                break;
        }
    }
    if (k >= vec_str.size())
        return '.';
    return vec_str[k];
}