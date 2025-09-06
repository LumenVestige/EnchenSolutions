//
// Created by sanenchen on 25-7-4.
//

#include "LeetCodes.h"

// 456周赛 T1 分割字符串
vector<string> LeetCodes::partitionString(string s) {
    /**
     * 将每一个字符，压入一个队列
     * 将队列里的数据与已知的ans相比较，看看存不存在目标数据（用哈希find?）
     */
    vector<string> ans;
    unordered_set<string> ans_set;
    stringstream temp_stream;
    vector<char> temp_chars; // 目前瓶颈在于拼接字符串耗时间
    for (const auto c: s) {
        //temp_chars.push_back(c);
        temp_stream.put(c);
        string temp_string = temp_stream.str();
        // cout << temp_string << endl;
        pair<unordered_set<string>::iterator, bool> inserted = ans_set.insert(temp_string);
        if (inserted.second == true) {
            ans.push_back(temp_string);
            temp_stream.str("");
            temp_stream.clear();
            //temp_chars.clear();
        }
    }

    // to_string(1);

    return ans;
}