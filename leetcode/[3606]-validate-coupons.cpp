//
// Created by sanenchen on 25-7-12.
//
#include "LeetCodes.h"

bool isTextRight(const string &codeValue) {
    if (codeValue == "")
        return false;
    // 逐个字符过
    int counter = 0;
    for (auto c: codeValue) {
        if (c <= '9' && c >= '0') counter += 1;
        if (c <= 'z' && c >= 'a') counter += 1;
        if (c <= 'Z' && c >= 'A') counter += 1;
        if (c == '_') counter += 1;
    }
    return counter == codeValue.length();
}

bool isTypeInclude(const string &codeValue) {
    return (codeValue == "electronics" || codeValue == "grocery" || codeValue == "pharmacy" || codeValue ==
            "restaurant");
}

vector<string> LeetCodes::validateCoupons(vector<string> &code, vector<string> &businessLine, vector<bool> &isActive) {
    // 校验优惠券是否有效
    // 三步 判断优惠券中的字符是否符合要求
    // 优惠券类型是否符合
    // 优惠券是否在有效期内
    // 可以直接将 isActive 视为有效的。
    // 第一步 遍历
    for (int i = 0; i < code.size(); i++) {
        if (!isTextRight(code[i]))
            isActive[i] = false;
        if (!isTypeInclude(businessLine[i]))
            isActive[i] = false;
    }
    vector<string> ans;
    vector<string> electronics;
    vector<string> grocery;
    vector<string> pharmacy;
    vector<string> restaurant;
    // 遍历 isActive 将有效的塞进去 准备排序
    for (int i = 0; i < isActive.size(); i++) {
        if (isActive[i]) {
            if (businessLine[i] == "electronics") {
                electronics.push_back(code[i]);
            } else if (businessLine[i] == "grocery") {
                grocery.push_back(code[i]);
            } else if (businessLine[i] == "pharmacy") {
                pharmacy.push_back(code[i]);
            } else if (businessLine[i] == "restaurant") {
                restaurant.push_back(code[i]);
            } else {
                // 其他情况
            }
        }
    }
    ranges::sort(electronics);
    ranges::sort(grocery);
    ranges::sort(pharmacy);
    ranges::sort(restaurant);
    ans.insert(ans.end(), electronics.begin(), electronics.end());
    ans.insert(ans.end(), grocery.begin(), grocery.end());
    ans.insert(ans.end(), pharmacy.begin(),pharmacy.end());
    ans.insert(ans.end(), restaurant.begin(), restaurant.end());

    return ans;
}
