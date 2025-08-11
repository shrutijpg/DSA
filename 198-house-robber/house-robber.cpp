class Solution {
public:
    int func(int ind,vector<int>& nums,vector<int>&dp){
        if(ind ==0) return nums[ind];
        if(ind<0) return 0;
        if (dp[ind] != -1)  return dp[ind];

        int pick = func(ind-2,nums,dp)+ nums[ind];

        int not_pick = func(ind-1,nums,dp);

        return dp[ind]= max(pick,not_pick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> dp(n,-1);
        
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(int i=2;i<n;i++){
            int take = nums[i]+dp[i-2];

            int non_take = dp[i-1];

            dp[i] = max(take, non_take);

        }
        return dp[n-1];
        
    }
};