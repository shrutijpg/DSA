class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums,k) - atMost(nums,k-1);
        
    }
    int atMost(vector<int>& nums, int k){
        int l=0;
        int r=0;
        int count =0;
        unordered_map<int,int> hash;
        while(r < nums.size()){
            hash[nums[r]]++;
            
            while(hash.size()>k){
                hash[nums[l]]--;

                if(hash[nums[l]] == 0) hash.erase(nums[l]);
                l++;
            }
            count = count +(r-l+1);
            r++;
            
        }
        return count;
    }
};