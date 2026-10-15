class Solution {
    vector<vector<int>> result;
    vector<int> curr;
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(0, nums);
        return result;
    }

    void dfs(int idx, vector<int>&nums) {
        result.push_back(curr);


        for (int i = idx; i < nums.size(); i++) {

        if (i > idx && nums[i] == nums[i - 1]) continue;

        curr.push_back(nums[i]);
        dfs(i+1, nums);
        curr.pop_back();
        }
        
    }
};
