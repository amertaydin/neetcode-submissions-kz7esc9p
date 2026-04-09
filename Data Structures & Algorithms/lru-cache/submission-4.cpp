class LRUCache {
public:
    int capacity;
    // map to key, and pair of value and where it's located
    unordered_map<int, pair<int, list<int>::iterator>> cache;
    list<int> order; // keeps order

    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (!cache.count(key)) return -1;
        order.erase(cache[key].second); // remove the iterator
        order.push_back(key);
        cache[key].second = prev(order.end()); // update the itr
        return cache[key].first;
    }
    
    void put(int key, int value) {
        if (cache.count(key)) {
            order.erase(cache[key].second);
        }
        order.push_back(key);
        cache[key]= {value, prev(order.end())};

        if (cache.size() > capacity) {
            int least = order.front();
            cache.erase(least);
            order.pop_front();
        }
    }
    
};
