// what
// I need to return the most frequent elements in the array..

// which pattern
// a map and a heap

// how
// 1-) count the frequencies, a frequency map
// 2-) push to the heap as pair, <freq, num>

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int ,int> freqMap;
        priority_queue<pair<int,int>> maxHeap;
        vector<int> result;

        for (int num : nums) {
            freqMap[num]++;
        }

        for (auto & itr: freqMap) {
            maxHeap.push({itr.second, itr.first});
        }

        while(k) {
            auto top = maxHeap.top();
            result.push_back(top.second);
            maxHeap.pop();
            k--;
        }

        return result;

    }
};
