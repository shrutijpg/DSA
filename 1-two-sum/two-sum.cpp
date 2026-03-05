class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        int n = nums.size();

        for(int i=0;i<n;i++){
            int sub = target - nums[i];

            if(mp.find(sub) != mp.end()) return {mp[sub],i};


            mp[nums[i]] = i;
        }
        return {};
    }
};