class Solution {
public:
    int func(int n,vector<int>&dp){
        int i=n;
        if(n==0 || n ==1) return 1;
        if(dp[i]!=-1) return dp[i];

        return dp[i]= func(n-1,dp)+func(n-2,dp);
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return func(n,dp);
    }
};