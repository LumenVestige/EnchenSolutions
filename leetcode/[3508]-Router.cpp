//
// Created by sanenchen on 25-9-20.
//
#include <bits/stdc++.h>
using namespace std;

class Router {
private:
    int limit;
    set<array<int, 3>> s;
    deque<array<int, 3>> packets;
public:
    Router(int memoryLimit) {
        limit = memoryLimit;
    }

    bool addPacket(int source, int destination, int timestamp) {
        if (!s.insert({source, destination, timestamp}).second) return false;
        // 判断是否超出limit
        if (limit == packets.size()) {
            packets.pop_front(); // 弹出最前面的
            if (s.find(array<int,3>{source, destination, timestamp}) == s.end())
            s.erase(s.begin());
        }
        packets.push_back({source, destination, timestamp});
        return true;
    }

    vector<int> forwardPacket() {
        if (packets.size() == 0) return {};
        vector<int> ans = {packets.front()[0], packets.front()[1], packets.front()[2]};
        packets.pop_front();
        s.erase(s.begin());
        return ans;
    }

    int getCount(int destination, int startTime, int endTime) {
        int ans = 0;
        for (auto& i : packets) {
            if (i[2] >= startTime && i[2] <= endTime && i[1] == destination) ans++;
        }
        return ans;
    }
};

int main() {
    Router r = Router(3);
    r.addPacket(1,5,1);
    r.addPacket(2,5,90);
    r.addPacket(2,5,90);
    r.addPacket(3,5,95);

    return 0;
}