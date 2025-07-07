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
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int ind =n-1;ind>=0;ind--){
            for(int prevInd=ind-1;prevInd>=-1;prevInd--){
                int len = dp[ind+1][prevInd+1];
                if(prevInd==-1 || nums[ind]>nums[prevInd]){
                    len = max(len,(1+ dp[ind+1][ind+1]));
                }
                dp[ind][prevInd+1] = len;
            }
        }
        return dp[0][-1+1];
    }
};