class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>sq;
        for(int i=0;i<nums.size();i++){
            long long num = nums[i];
            
            num = (num*num);
            sq.push_back(num);
            
            
        }
        sort(sq.begin(),sq.end());
        return sq;
    }
};