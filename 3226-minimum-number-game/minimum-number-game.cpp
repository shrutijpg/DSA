class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        vector<int> arr;
        sort(nums.begin(), nums.end());
        
        while (!nums.empty()) {
            int alice = nums.front();
            nums.erase(nums.begin());
            int bob = nums.front();
            nums.erase(nums.begin());
            
            arr.push_back(bob);
            arr.push_back(alice);
        }
        return arr;
        
    }
};