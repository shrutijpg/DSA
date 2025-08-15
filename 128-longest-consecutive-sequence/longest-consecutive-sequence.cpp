class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;

        sort(nums.begin(), nums.end());
        int longest = 1;
        int currLen = 1;

        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == nums[i-1]) {
                // skip duplicates
                continue;
            }
            if(nums[i] == nums[i-1] + 1) {
                currLen++;
            } else {
                longest = max(longest, currLen);
                currLen = 1; // reset
            }
        }

        longest = max(longest, currLen);
        return longest;
    }
};
