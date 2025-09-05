#include<bits/stdc++.h>
using namespace std;

class SnapshotArray {
private:
    unordered_map<int, vector<vector<int> > > changeLogs;
    int snapId = 0;
    
    int lowerBound(vector<vector<int>>& changeLog, int targetId) {
        int left = -1, right = changeLog.size();
        while(left + 1 != right) {
            int mid = left + (right - left) / 2;
            if (changeLog[mid][0] >= targetId) right = mid;
            else left = mid;
        }
        return right;
    }
public:
    SnapshotArray(int length) {
        for (int i = 0; i < length; ++i) {
            changeLogs[i] = {};
        }
    }
    
    void set(int index, int val) {
        changeLogs[index].push_back({snapId, val});
    }
    
    int snap() {
        return snapId++;
    }
    
    int get(int index, int snap_id) {
        int location = lowerBound(changeLogs[index], snap_id + 1) - 1;
        if (location == -1) return 0;
        return changeLogs[index][location][1];
    }
};