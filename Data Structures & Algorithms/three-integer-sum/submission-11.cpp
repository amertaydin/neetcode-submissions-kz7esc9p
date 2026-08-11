// what
// I need to find the 3 indices where their sum is equal to 0, indices needs to be distinct

// which pattern
// I can do it with two pointers

// how
// I can firs sort it and go from left and right
// I can also loop inside, until left and right is not the same number again

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++) {
        int l = i + 1;
        int r = nums.size() - 1;

        if (nums[i] > 0) break;

        if (i > 0 && nums[i] == nums[i-1]) continue; // don't count duplicate head

        while (l < r) {
            if (nums[l] + nums[r] + nums[i] == 0) {
                result.push_back({nums[l], nums[r], nums[i]});
                l++;
                r--;

                while (l < r && nums[l] == nums[l-1]) {
                    l++;
                }
                while (r > l && nums[r] == nums[r+1]) {
                    r--;
                }
            } else {
                if (nums[l] + nums[r] + nums[i] > 0) {
                    r--;
                } else {
                    l++;
                }
            }

        }
    }
        return result;
        
        
    }
};
