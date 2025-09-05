#include<bits/stdc++.h>
using namespace std;

class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> changeLogs; // 前面一个表示键 后面的pair 表示版本和值
    int lowerBound(vector<pair<int, string>>& changeLog, int targetTime) {
        int left = -1, right = changeLog.size();
        while (left + 1 != right) {
            int mid = left + (right - left) / 2;
            if (changeLog[mid].first >= targetTime) right = mid;
            else left = mid;
        }
        return right;
    }
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        changeLogs[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        int location = lowerBound(changeLogs[key], timestamp + 1) - 1;
        if (location == -1) return "";
        return changeLogs[key][location].second;
    }
};