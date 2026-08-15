// what 
// find the target

// how
// push every number in the matrix into a 1d vector and do binary search

// what pattern binary search

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int> nums;

        for(auto row : matrix) {
            for (auto num : row) {
                nums.push_back(num);
            }
        }

        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            int middle = (l+r) / 2;

            if (nums[middle] == target) return true;

            if (nums[middle] < target) l++;

            if (nums[middle] > target) r--;
        }

        return false;
        
    }
};
