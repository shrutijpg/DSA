class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        int posI=0,negI =1;

        for(int i =0;i<n;i++){
            if(nums[i] <0){
                ans[negI] = nums[i];
                negI += 2;
            }
            else{
                ans[posI] = nums[i];
                posI += 2;
            }
        }
        return ans;
    }
};