class Solution {
public:
    int func(int ind,vector<int>&coins,int amount,vector<vector<int>>&dp){
        if (ind == 0) {
            return (amount % coins[0] == 0) ? 1 : 0;
        }
        if(dp[ind][amount] != -1) return dp[ind][amount];

        int notTake = func(ind-1,coins,amount,dp);
        int take =0;
        if(coins[ind] <= amount) take = func(ind,coins,amount-coins[ind],dp);


        return dp[ind][amount] = take + notTake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));

        return func(n-1,coins,amount,dp);
    }

};