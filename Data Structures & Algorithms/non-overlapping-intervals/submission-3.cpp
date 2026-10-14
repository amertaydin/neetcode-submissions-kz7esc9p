class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int start = intervals[0][0];
        int end = intervals[0][1];
        int minToRemove = 0;

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < end) {
                end = min(end, intervals[i][1]);
                minToRemove++;
            } else {
                end = intervals[i][1];
            }
        }

        return minToRemove;
    }
};
