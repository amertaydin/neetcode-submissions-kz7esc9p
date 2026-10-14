class Solution {
    vector<vector<int>> result;
    vector<int> curr;
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        
        dfs(nums, target, curr, 0, 0);

        return result;
    }

    void dfs(vector<int> nums, int target, vector<int> & curr, int sum, int idx) {
        if (sum == target) {
            result.push_back(curr);
            return;
        }

        for (int i = idx; i < nums.size(); i++) {
            if (nums[i] + sum > target) continue;
            curr.push_back(nums[i]);
            dfs(nums, target, curr, sum + nums[i], i);
            curr.pop_back();
        }
    }
};
