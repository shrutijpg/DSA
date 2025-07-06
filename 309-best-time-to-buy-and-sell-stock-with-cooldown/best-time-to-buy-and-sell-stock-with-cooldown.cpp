class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        
        // Initialize variables to track states
        int ahead2_buy = 0;  // dp[i+2][1]
        int ahead1_buy = 0;  // dp[i+1][1]
        int ahead1_notBuy = 0;  // dp[i+1][0]
        int curr_buy, curr_notBuy;
        
        for (int ind = n-1; ind >= 0; ind--) {
            // Can buy
            curr_buy = max(-prices[ind] + ahead1_notBuy, ahead1_buy);
            
            // Can sell (with cooldown)
            curr_notBuy = max(prices[ind] + ahead2_buy, ahead1_notBuy);
            
            // Update for next iteration
            ahead2_buy = ahead1_buy;
            ahead1_buy = curr_buy;
            ahead1_notBuy = curr_notBuy;
        }
        
        return ahead1_buy;
    }
};
