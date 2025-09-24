class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int n = nums.size();
        if(nums.size()==0){
            return 0;
        }
        int cur_max= nums[0];
        int mmax = nums[0];
        for(int i=1;i<n;i++){
            cur_max = max(nums[i],cur_max+nums[i]);
            mmax = max(mmax,cur_max);
            
        }
        return mmax;

    }
};