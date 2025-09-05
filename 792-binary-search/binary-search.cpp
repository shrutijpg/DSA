class Solution {
public:
    int func(vector<int>& nums,int low,int high,int t){

        if(low>high) return -1;

        int mid = low+(high-low)/2;
        if(t==nums[mid]) return mid;
        else if(t>nums[mid]) return func(nums,mid+1,high,t);
        else  return func(nums,low,mid-1,t);
        

    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        return func(nums,0,n-1,target);
    }
};