class Solution {
public:
    int func(int ind, vector<int>& nums, vector<int>& dp) {
        int n = nums.size();
        if (ind >= n - 1) return 0; // No more jumps needed if we are at or beyond last index
        if (dp[ind] != -1) return dp[ind];

        int minJumps = INT_MAX;
        int maxStep = nums[ind];
        for (int i = 1; i <= maxStep; i++) {
            int next = func(ind + i, nums, dp);
            if (next != INT_MAX) // avoid overflow
                minJumps = min(minJumps, 1 + next);
        }

        return dp[ind] = minJumps;
    }

    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return func(0, nums, dp);
    }
};
