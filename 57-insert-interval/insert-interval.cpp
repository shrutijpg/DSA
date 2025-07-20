class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int n = intervals.size();
        int i = 0;

        // Step 1: Add all intervals before newInterval (non-overlapping to the left)
        while (i < n && intervals[i][1] < newInterval[0]) {
            res.push_back(intervals[i]);
            i++;
        }

        // Step 2: Merge overlapping intervals with newInterval
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);  // Fixed here
            i++;
        }
        res.push_back(newInterval);

        // Step 3: Add remaining intervals (non-overlapping to the right)
        while (i < n) {
            res.push_back(intervals[i]);
            i++;
        }

        return res;
    }
};
