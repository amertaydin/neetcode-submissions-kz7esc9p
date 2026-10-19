class Solution {
public:
    bool canJump(vector<int>& nums) {
        int goal = nums.size() - 1;

        for (int index = nums.size() - 2; index >= 0; index--) {
                if (index + nums[index] >= goal) {
                    goal = index;
                }
                
        }

        if (goal <= 0) return true;
        return false;
    }
};
