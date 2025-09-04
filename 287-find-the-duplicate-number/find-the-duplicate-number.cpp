class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int count=0;
        sort(nums.begin(),nums.end());
        if(nums[n-2] == nums[n-1]) return nums[n-1];
        for(int i=0;i<n;i++){
            if(nums[i]==nums[i+1]) return nums[i];
        }
        return -1;
    }
};