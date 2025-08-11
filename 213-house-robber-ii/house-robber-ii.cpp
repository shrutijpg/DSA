class Solution {
public:
    int rob1(vector<int>& nums){
        int n = nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        vector<int>  dp (n+1,-1);

        dp[0] = nums[0];
        dp[1] = max(nums[1],nums[0]);

        for(int i =2;i<n;i++){
            int take = nums[i] + dp[i-2];
            int not_take = dp[i-1];

            dp[i] = max(take,not_take);

        }
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> temp1 ,temp2;
        for(int i=0;i<n;i++){
            if(i != 0) temp1.push_back(nums[i]);
            if(i != n-1)  temp2.push_back(nums[i]);


        }
        return max(rob1(temp1),rob1(temp2));
        
    }
};