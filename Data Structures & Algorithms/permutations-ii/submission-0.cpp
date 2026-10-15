class Solution {
    vector<vector<int>> result;
    unordered_set<int> used;
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> curr;
        dfs(curr, nums);
        return result;
    }

    void dfs(vector<int> &curr, vector<int> &nums) {
        if (curr.size() == nums.size()) {
            result.push_back(curr);
            return; 
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used.count(i)) continue;

            if (i > 0 && nums[i] == nums[i - 1] && used.count(i - 1)) continue;

            used.insert(i);
            curr.push_back(nums[i]);
            
            dfs(curr, nums);
            
            curr.pop_back();
            used.erase(i);
        }
    }
};