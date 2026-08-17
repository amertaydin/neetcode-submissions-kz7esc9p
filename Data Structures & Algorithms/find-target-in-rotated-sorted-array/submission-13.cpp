// what
// return the index of target

// which pattern
// binary search

// how
// after finding the middle, check the target is between the middle and left, if not check right side, 

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            int middle = (l + r) / 2;
            if (nums[middle] == target) return middle;

            if (nums[middle] >= nums[l]) {//leftside sorted
                
                if (target >= nums[l] && target < nums[middle]) {
                    r = middle - 1;
                } else {
                    l = middle + 1;
                }

            } else { // rightside
                if (target <= nums[r] && target > nums[middle]) {
                    l = middle + 1;
                } else {
                    r = middle - 1;
                }
            }
        }

        return -1;
    }
};
