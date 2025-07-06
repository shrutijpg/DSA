class Solution {
public:
    int func(int ind, int tranNo, int k, vector<int>& prices, int n, vector<vector<int>>& dp) {
        if (ind == n || tranNo == 2 * k) return 0;
        if (dp[ind][tranNo] != -1) return dp[ind][tranNo];

        // Buy
        if (tranNo % 2 == 0) {
            return dp[ind][tranNo] = max(
                -prices[ind] + func(ind + 1, tranNo + 1, k, prices, n, dp),
                func(ind + 1, tranNo, k, prices, n, dp)
            );
        } 
        // Sell
        else {
            return dp[ind][tranNo] = max(
                prices[ind] + func(ind + 1, tranNo + 1, k, prices, n, dp),
                func(ind + 1, tranNo, k, prices, n, dp)
            );
        }
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2 * k, -1));
        return func(0, 0, k, prices, n, dp);
    }
};
