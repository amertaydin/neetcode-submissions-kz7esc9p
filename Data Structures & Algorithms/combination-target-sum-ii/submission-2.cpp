class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> curr;
        
        dfs(result, curr, 0, 0, target, candidates);
        return result;
    }

    void dfs(vector<vector<int>> &result, vector<int> &curr, int idx, int sum, int target, vector<int> &candidates) {
        if (sum == target) {
            result.push_back(curr);
            return;
        }


        for (int i = idx; i < candidates.size(); i++) {

            if (i > idx && candidates[i] == candidates[i -1]) continue;
            if (sum + candidates[i] > target) continue;

            curr.push_back(candidates[i]);
            dfs(result, curr, i + 1, sum + candidates[i], target, candidates);
            curr.pop_back();
        }
    }
};
