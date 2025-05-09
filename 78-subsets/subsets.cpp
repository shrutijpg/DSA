class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int subset = 1<<n;
        vector<vector<int>> ans;
        for(int mask =0;mask<subset;mask++){
            vector<int> list;
            for(int i =0;i<n;i++){
                if((mask & (1<<i))){
                    list.push_back(nums[i]);
                }
            }
            ans.push_back(list);
        }
        return ans;
        
        
    }
};