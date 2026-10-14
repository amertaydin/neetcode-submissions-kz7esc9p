class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        bool inserted = false;
        vector<vector<int>> result;

        // insert at end
        for (auto & interval : intervals) {
            if (newInterval[1] < interval[0]) {
                if (!inserted) {
                    result.push_back(newInterval);
                    inserted = true;
                }
                result.push_back(interval);
            } else if(newInterval[0] > interval[1]) {
                result.push_back(interval);
            } else {
                newInterval[0] = min(newInterval[0], interval[0]);
                newInterval[1] = max(newInterval[1], interval[1]);
            }
            
        }
        // inset at the end
        if (!inserted) {
            result.push_back(newInterval);
        }
        return result;
    }
};
