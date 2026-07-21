// what
// need to find which numbers in an array add up to the target
// only one correct solution
// return the answer with the smaller index first

// which pattern
// can use map

// how
// store the values of the keys, compare it with target - num, exists
// if exists then return the indices

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> targetMap;

        for (int i = 0; i < nums.size(); i++) {
            int remaining = target - nums[i];
            if (targetMap.count(remaining)) {
                return {targetMap[remaining], i};
            }
            targetMap[nums[i]] = i;
        }
    }
};
