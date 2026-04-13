class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        vector<int> results;
        priority_queue<pair<int,int>> pq;

        for (int num : nums) {
            freqMap[num]++;
        }

        for (auto [num, occ] : freqMap) {
            pq.push({occ, num});
        }

        while (k) {
            auto [occ, num] = pq.top();
            pq.pop();
            results.push_back(num);
            k--;
        }


        return results;

    }
};
