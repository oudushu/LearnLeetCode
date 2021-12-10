/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存机制
 */

// @lc code=start
struct DLinkedNode {
    int key, value;
    DLinkedNode *pre;
    DLinkedNode *next;
    DLinkedNode(): key(0), value(0), pre(nullptr), next(nullptr) {}
    DLinkedNode(int _key, int _value): key(_key), value(_value), pre(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    map<int, DLinkedNode *> cache;
    DLinkedNode *head;
    DLinkedNode *tail;
    int size;
    int capacity;

    void addToHead(DLinkedNode *node) {
        node->pre = head;
        node->next = head->next;
        head->next->pre = node;
        head->next = node;
    }

    void removeNode(DLinkedNode *node) {
        node->pre->next = node->next;
        node->next->pre = node->pre;
    }

    void moveToHead(DLinkedNode *node) {
        removeNode(node);
        addToHead(node);
    }

    DLinkedNode *removeTail() {
        DLinkedNode *node = tail->pre;
        removeNode(node);
        return node;
    }

public:
    LRUCache(int _capacity) {
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->pre = head;
        capacity = _capacity;
        size = 0;
    }
    
    int get(int key) {
        if (!cache.count(key)) return -1;
        DLinkedNode *node = cache[key];
        moveToHead(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if (!cache.count(key)) {
            DLinkedNode *node = new DLinkedNode(key, value);
            cache[key] = node;
            addToHead(node);
            ++ size;
            if (size > capacity) {
                DLinkedNode *removed = removeTail();
                cache.erase(removed->key);
                delete removed;
                -- size;
            }
        } else {
            DLinkedNode *node = cache[key];
            node->value = value;
            moveToHead(node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

