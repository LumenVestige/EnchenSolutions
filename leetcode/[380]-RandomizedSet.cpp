#include <bits/stdc++.h>
using namespace std;

class RandomizedSet {
private:
    unordered_map<int, int> valToIndex;
    vector<int> value;
    default_random_engine rand;
public:
    RandomizedSet() {
        rand.seed(random_device()());
    }
    
    bool insert(int val) {
        if (valToIndex.count(val)) {
            return false;
        } else {
            valToIndex[val] = value.size();
            value.push_back(val);
            return true;
        }
    }
    
    bool remove(int val) {
        if (!valToIndex.count(val)) {
            return false;
        }
        // 获取对应的下标
        int deIndex = valToIndex[val];
        // 与最后一个交换
        valToIndex[value[value.size() - 1]] = deIndex;
        value[deIndex] = value[value.size() - 1];
        value.pop_back();
        valToIndex.erase(val);
        return true;
    }
    
    int getRandom() {
        // 随机数
        uniform_int_distribution<int> dist(0, value.size() - 1);
        return value[dist(rand)];
    }
};
 