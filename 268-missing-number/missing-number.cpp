class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int total = n*(n+1)/2;

        int sum =0;
        for(int num: nums){sum+=num;}
        return total-sum;

        //int num;
        //sort(nums.begin(),nums.end());
        //for(int i=0;i<n;i++){
           // if(nums[i] != i){
           //     return i;
           // }
       // }
        //return nums.size();


        
    }
};