#include <vector>
#include <algorithm>

class Solution {
public:
    int func(int ind,int prevInd,int n,vector<int>& nums,vector<vector<int>>&dp){
        if(ind == n) return 0;
        if(dp[ind][prevInd+1] != -1) return dp[ind][prevInd+1];

        //Not take 
        int len = func(ind+1,prevInd,n,nums,dp);
        if(prevInd==-1 || nums[ind]>nums[prevInd]){
            len = max(len,(1+ func(ind+1,ind,n,nums,dp)));
        }
        return dp[ind][prevInd+1] = len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return func(0,-1,n,nums,dp);
    }
};