//
// Created by sanenchen on 25-7-13.
//

#include "../LeetCodes.h"

string LeetCodes::processStr(string s) {
    vector<char> vec_str;
    string result;
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
    for (const auto it : vec_str) {
        result += it;
    }
    return result;
}