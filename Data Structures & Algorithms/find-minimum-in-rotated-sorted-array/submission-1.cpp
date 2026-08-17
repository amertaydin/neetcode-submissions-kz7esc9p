// what
// find the minumum element in this rotated array

// which pattern -> binary search

// how
// if middle is bigger than right, increase middle + 1
// if middle is smaller than 

class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0;
        int r = nums.size() - 1;

        while (l < r) {
            int middle = (l + r) / 2;

            if (nums[middle] > nums[r]) {
                l = middle + 1;
            } else {
                r = middle;
            }
        }
        return nums[l];
    }
};
