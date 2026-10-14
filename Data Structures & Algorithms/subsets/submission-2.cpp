class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> cur;
        int idx = 0;

        dfs(result, nums, idx, cur);
        return result;
    }

    void dfs(vector<vector<int>> &result, vector<int> nums, int idx, vector<int> &cur) {
        if (idx == nums.size()) {
            result.push_back(cur);
            return;
        }

        cur.push_back(nums[idx]);
        dfs(result, nums, idx + 1, cur);
        cur.pop_back();

        dfs(result, nums, idx + 1, cur);
    }


};
