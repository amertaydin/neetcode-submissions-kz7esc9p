class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            int middle = (l + r) / 2;

            if (nums[middle] == target) return middle;

            if (nums[middle] < target) l++;

            if (nums[middle] > target) r--;
        }

        return -1;
    }
};
