//
// Created by sanenchen on 25-8-2.
//
#include <bits/stdc++.h>
using namespace std;

int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
    vector<int> endTime;
    for (int i = 0; i < landStartTime.size(); ++i) {
        int landEndTime = landStartTime[i] + landDuration[i];
        for (int j = 0; j < waterStartTime.size(); ++j) {
            if (landEndTime >= waterStartTime[j]) {
                endTime.push_back(landEndTime + waterDuration[j]);
            } else {
                endTime.push_back(waterStartTime[j] + waterDuration[j]);
            }
        }
    }

    for (int i = 0; i < waterStartTime.size(); ++i) {
        int waterEndTime = waterStartTime[i] + waterDuration[i];
        for (int j = 0; j < landStartTime.size(); ++j) {
            if (waterEndTime >= landStartTime[j]) {
                endTime.push_back(waterEndTime + landDuration[j]);
            } else {
                endTime.push_back(landStartTime[j] + landDuration[j]);
            }
        }
    }
    int ans = INT_MAX;
    for (auto &i : endTime) {
        ans = min(ans, i);
    }
    return ans;
}

int main() {
    vector<int> landStartTime = {2, 8};
    vector<int> landDuration = {4, 1};
    vector<int> waterStartTime = {6};
    vector<int> waterDuration = {3};
    cout << earliestFinishTime(landStartTime, landDuration, waterStartTime, waterDuration);
    return 0;
}