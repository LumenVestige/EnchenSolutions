#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int key, val;
    Node* next;
    Node* prev;
    Node(int k, int v) : key(k), val(v) {}    
};

class DoubleList {
private:
    Node* head;
    Node* tail;
    int size;
public:
    DoubleList() {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    // 添加到末尾
    void addLast(Node* x) {
        x->prev = tail->prev;
        x->next = tail;
        tail->prev->next = x;
        tail->prev = x;
        size++;
    }
    // 删除指定node
    void remove(Node* x) {
        x->prev->next = x->next;
        x->next->prev = x->prev;
        size--;
    }
    Node* removeFirst() {
        // 删除第一个节点 并且返回
        if (head->next == tail)
            return nullptr;
        Node* first = head->next;
        remove(first);
        return first;
    }
    int getSize() {
        return size;
    }
};


class LRUCache {
private:
    unordered_map<int, Node*> cnt;
    int cap;
    DoubleList db;
public:
    LRUCache(int capacity) {
        this->cap = capacity;
        db = DoubleList();
    }
    
    int get(int key) {
        if (cnt.count(key)) {
            Node* node = cnt[key];
            int value = node->val;
            db.remove(node);          // 从链表中移除
            db.addLast(node);         // 重新添加到末尾（标记为最近使用）
            return value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (cnt.count(key)) {
            Node* node = cnt[key];
            db.remove(node);
            node->val = value;
            db.addLast(node);
            return;
        }
        if (db.getSize() == cap) {
            // 删掉最前面那个
            auto f = db.removeFirst();
            cnt.erase(f->key);
        }
        Node* n = new Node(key, value);
        cnt[key] = n;
        db.addLast(n);
    }
};