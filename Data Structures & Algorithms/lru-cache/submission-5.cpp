class LRUCache {
public:
    int capacity;
    // key, <value, itr>
    unordered_map<int, pair<int, list<int>::iterator>> cache;
    list<int> order;

    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (!cache.count(key)) return -1;
        // update iterator
        order.erase(cache[key].second);
        order.push_back(key);
        // change order
        cache[key].second = prev(order.end());
        return cache[key].first;
    }
    
    void put(int key, int value) {
        if (cache.count(key)) {
            order.erase(cache[key].second);
        } else if (cache.size() >= capacity) {
            int toDelete = order.front();
            cache.erase(toDelete);
            order.pop_front();
        }
        order.push_back(key);
        cache[key] = {value, prev(order.end())};
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */