// what
// I need to find the if there's a duplicate in an array. return true
// if it's the case

// which pattern
// I can solve this with using a map

// how
// create a map, have a loop, check if that key exists in the map

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> duplicateMap;

        for (int num : nums) {
            if (duplicateMap.count(num))
                return true;
            duplicateMap[num]++;
        }
        return false;
    }
};