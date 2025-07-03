//
// Created by sanenchen on 25-7-2.
//

#ifndef HASHMAP_H
#define HASHMAP_H
#include <iostream>
#include <list>
#include <vector>

using namespace std;

// 模板类
template<typename KeyType, typename ValueType>
class HashMap {
    vector<list<ValueType>> data; // 简单用vector模拟存储
private:
    vector<list<pair<KeyType, ValueType>>> buckets;

public:
    HashMap():buckets(100) {}
    // 返回对应key的value引用，若不存在则插入默认值
    ValueType &operator[](const KeyType &key) {
        // 哈希
        hash<KeyType> hasher;
        size_t newIndex = hasher(key) % 100;
        // cout << "newIndex: " << newIndex << endl;
        auto& target_bucket = buckets[newIndex];
        // 先查找是否有该key

        for (auto& it : target_bucket) {
            /** 为什么auto加个&？
             *  加上& 就代表这是一个别名，不加的话，就是一个拷贝，不是元素的本身
             *  it将会是一个局部变量
             *  生命周期仅限于本次循环当中
             **/
            if (it.first == key) {
                return it.second;
            }
        }

        // 没找到，插入默认值
        // 构建一个链表
        target_bucket.emplace_back(key, ValueType{});
        return target_bucket.back().second;  // 返回新插入元素的引用
    }

    void erase(const KeyType &key) {
        hash<KeyType> hasher;
        size_t index = hasher(key) % 100;
        auto& target_bucket = buckets[index];
        for (auto it = target_bucket.begin(); it !=target_bucket.end(); ++it) {
            if (it->first == key) {
                target_bucket.erase(it);
                return;
            }
        }
    }
};


#endif //HASHMAP_H
