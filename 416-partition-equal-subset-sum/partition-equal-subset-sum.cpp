class Solution {
public:
    bool func(int n, int k, vector<int> &arr,vector<vector<int>>&dp){
        if(k==0) return true;
        if(n==0) return (arr[0] == k);
        if(dp[n][k] != -1) return dp[n][k];

        bool notTake= func(n-1,k,arr,dp);

        bool Take = false;
        if(k>=arr[n]){
            Take = func(n-1,(k-arr[n]),arr,dp);
        }

    return dp[n][k] = Take|notTake;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    return func(n-1,k,arr,dp);
}

//main function
    bool canPartition(vector<int>& nums) {
        int totsum=0;
        
        int n = nums.size();
        for(int i =0;i<n;i++){
            totsum += nums[i];
        }
        if(totsum %2) return false;
        int target = totsum/2;

        return subsetSumToK(n,target,nums);
    }
};