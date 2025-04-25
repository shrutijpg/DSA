class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        // Sort intervals by end time
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int count = 1; // count of non-overlapping intervals
        int end = intervals[0][1];

        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] >= end) {
                // non-overlapping
                end = intervals[i][1];
                count++;
            }
        }

        // total intervals - non-overlapping intervals = intervals to remove
        return intervals.size() - count;
    }
};